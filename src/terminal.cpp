#include "terminal.h"
#include "mypipe.h"
#include "utility.h"

int run_cmd(std::vector<char*> argv){
    mypipe pipe;
    pid_t pid = fork();

    if (pid == -1) {
        std::cerr << "Fork failed\n";
        return 1;
    }

    if (pid == 0) {  // child
        pipe.redirect();
        execvp(argv[0], argv.data());
        perror("execvp failed");
        exit(1);
    } else {  // parent
        wait(nullptr); // wait for child to finish
        std::string output = pipe.read();
        std::cout << output;
        return 0;
    }
}

void terminal_app(){
    std::string line;
    while (true) {
        std::cout << "$ ";
        std::getline(std::cin, line);
        if (line == "exit") break;

        auto tokens = cmd2vec(line);
        if (tokens.empty()) continue;
        auto args = castArgs(tokens);
        run_cmd(args);
    }
}
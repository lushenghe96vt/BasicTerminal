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
    } 
    else {  // parent
        wait(nullptr); // wait for child to finish
        std::string output = pipe.read();
        std::cout << output;
        return 0;
    }
}

void terminal_app(){
    char input[1024];
    while (true) {
        std::cout << "<< ";
        std::cin.getline(input, sizeof(input));

        if (std::cin.eof() || std::string(input) == "exit") {
            break;
        }
        std::vector<std::string> tokens = cmd2vec(input, ' ');
        if (tokens.empty()) {
            continue;
        }

        std::vector<char*> args = castArgs(tokens);
        run_cmd(args);
    }
}
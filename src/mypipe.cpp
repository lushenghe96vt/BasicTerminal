#include "mypipe.h"

mypipe::mypipe(){
    if (pipe(fd.data()) == -1) {
        throw std::runtime_error("Pipe creation failed");
    }
}
    
mypipe::~mypipe(){
    close(fd[0]);
    close(fd[1]);
}

void mypipe::redirect(){
    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);
}

std::string mypipe::read(){
    close(fd[1]);
    std::ostringstream oss;
    char buffer[1024];
    ssize_t count;
    while ((count = ::read(fd[0], buffer, sizeof(buffer))) > 0) {
        oss.write(buffer, count);
    }
    return oss.str();
}
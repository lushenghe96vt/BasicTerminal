#include "utility.h"

std::vector<char*> castArgs(const std::vector<std::string>& cmd){
    std::vector<char*> args;
    for (const auto& str : cmd) {
        args.push_back(const_cast<char*>(str.c_str()));
    }
    args.push_back(nullptr);
    return args;
}

std::vector<std::string> cmd2vec(const std::string& command, char delimiter){
    std::vector<std::string> result;
    std::istringstream iss(command);
    std::string token;
    while (std::getline(iss, token, delimiter)) {
        if (!token.empty()) result.push_back(token);
    }
    return result;    
}
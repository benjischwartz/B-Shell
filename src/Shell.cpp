#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <strstream>
#include <sys/wait.h>
#include <vector>
#include <unistd.h>
#include "../include/Shell.h"

void Shell::run() 
{
    bool status = true;
    while (status)
    {
        // Show prompt
        std::cout << "> ";

        // Read input
        std::string input;
        std::getline(std::cin, input);
        Command c;
        if (!parseCommand(input, c)) {
            std::cerr << "Failed to parse command";
            break;
        }
        executeCommand(c);
    }
}

bool Shell::parseCommand(std::string& input, Command& c)
{
    std::stringstream ss(input);
    std::string cmd;
    ss >> cmd;
    if (!BuiltinCommandList.count(cmd) && !ExternalCommandList.count(cmd)) {
        return false;
    }
    c.command = cmd;

    std::vector<std::string> args;
    std::string temp;
    while (ss >> temp) {
        args.push_back(temp);
    }
    c.argv = args;
    return true;
}


bool Shell::executeCommand(Command& c) 
{
    // Built-in command
    if (BuiltinCommandList.count(c.command)) {
        std::cout << "That's a built-in command!\n";
    }
    // External command
    else {
        std::cout << "That's an external command!\n";
        std::vector<char*> cstrings;
        cstrings.reserve(c.argv.size());
        for (size_t i = 0; i < c.argv.size(); ++i) {
            cstrings.push_back(const_cast<char*>(c.argv[i].c_str()));
        }

        pid_t pid = fork();
        if (pid == -1) 
        {
            std::cerr << "Failed to fork";
        } 
        else if (pid == 0) 
        {
            execvp(c.command.c_str(), &cstrings[0]);
        }
        else {
            wait(NULL);
        }
    }
    return true;
}
    

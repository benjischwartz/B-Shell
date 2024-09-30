#include <iostream>
#include <memory>
#include <string>
#include "Shell.h"

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

        /*    
        std::unique_ptr<Command> command = parseInput(input);
        status = executeCommand(std::move(command));
        */
    }
}

/* 
    General structure of Linux/Unix command: 
      command [-flag(s)] [-option(s) [value]] [argument(s)]
    For now, we will just do:
      command [argument(s)]
*/
std::unique_ptr<Command> Shell::parseInput(const std::string& input) 
{

    std::cout << input << std::endl;
    return nullptr;
}


    

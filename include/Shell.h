#include <memory>
#include <string>
#include "CommandParser.h"
#include "Environment.h"
#include "History.h"

class Shell {
public:
    void run();

private:
    /*
    CommandParser parser;
    Environment env;
    History history;
    */

    std::unique_ptr<Command> parseInput(const std::string& input);
    bool executeCommand(std::unique_ptr<Command> command) 
    {
        return command->execute();
    }
};



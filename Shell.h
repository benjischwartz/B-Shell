#include <string>
#include "CommandParser.h"
#include "Environment.h"
#include "History.h"

class Shell {
public:
    void run();

private:
    CommandParser parser;
    Environment env;
    History history;

    void showPrompt();
    std::string readInput();
    void parseInput(const std::string& input);

    // CommandType either built-in or external
    template<typename CommandType>
    void executeCommand(const CommandType& command) {
        command.execute();
    }
};

#include <memory>
#include <string>
#include <unordered_set>
#include <vector>

/* 
    General structure of Linux/Unix command: 
      command [-flag(s)] [-option(s) [value]] [argument(s)]
    For now, we will just do:
      command [argument(s)]
*/

struct Command {
    std::string command;
    std::vector<std::string> argv;
};

class Shell {
public:
    void run();

private:
    bool parseCommand(std::string& input, Command& c);
    bool executeCommand(Command& c);
    std::unordered_set<std::string> BuiltinCommandList {
        "cd",
        "exit",
        "pwd",
        "echo",
        "help",
        "export",
        "unset",
        "history",
    };
    std::unordered_set<std::string> ExternalCommandList {
        "ls",
        "grep",
        "cat"
    };
};



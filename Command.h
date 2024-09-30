#include <string>
#include <vector>
#include <unistd.h>

class Command {
public:
    virtual bool execute() const = 0;
};

// ls, grep, awk
class ExtCommand : Command {
    ExtCommand(const std::string& command_, const std::vector<std::string>& args_) : 
        args(std::move(args_)), command(std::move(command_))
    {
        // Fork new process
        pid_t pid = fork();
        if (pid < 0) 
        {
            // Failed to fork
        }
        else if (pid == 0)
        {
            /* 
             * Child Process
             * Use execvp() with args
            */
        }
        else 
        {
            /* 
             * Parent Process
             * Wait on child process
            */

        }
    };

public:
    bool execute() const override {
        return true;

    };

private:
    std::string command;
    std::vector<std::string> args;
};

class BuiltinCommand : Command {
private:


};

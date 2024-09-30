#include <vector>
#include "Command.h"

class CommandParser 
{
public:
    Command parse(const std::string& input);

private:
    std::vector<std::string> tokenise(const std::string& input);
};

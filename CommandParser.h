#include <vector>
#include "Command.h"

template<typename CommandType>
class CommandParser 
{
public:
    CommandType parse(const std::string& input);

private:
    std::vector<std::string> tokenise(const std::string& input);
};

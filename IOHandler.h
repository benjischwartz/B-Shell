#include <string>

template <typename StreamType>
class IOHandler {
public:
    void read(StreamType& stream);
    void write(StreamType& stream, const std::string& data);
    void redirectInput(const std::string& filename);
    void redirectOutput(const std::string& filename);
    void setupPipe(int read_fd, int write_fd);
};

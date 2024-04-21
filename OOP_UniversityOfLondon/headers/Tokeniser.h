#include <vector>
#include <string>

class Tokeniser
{
    public:
        Tokeniser() = default;
        ~Tokeniser() = default;
        std::vector<std::string> tokenise(const std::string& input, const char separator);
};
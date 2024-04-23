#include <vector>
#include <string>

class tokeniser
{
    public:
        tokeniser() = default;
        ~tokeniser() = default;
        std::vector<std::string> tokenise(const std::string line, const char delimiter);
};
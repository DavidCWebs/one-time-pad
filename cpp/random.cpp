#include "random.hpp"

std::string randomPrintableChars()
{
    std::random_device seed;
    std::mt19937 gen(seed());
    std::uniform_int_distribution<int> dist(33, 126);
    std::stringstream output;

    for (int i = 0; i < 1000; i++) {
        output << (char)dist(gen);
    }

    return output.str();
}

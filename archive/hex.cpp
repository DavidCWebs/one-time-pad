#include <iostream>
#include <sstream>
#include <cstring>
/**
 * @see https://stackoverflow.com/a/5427762/3590673
 * @return [description]
 */
int main()
{
    const char* tempBuf = "D";

    std::stringstream ss;

    const char* it = tempBuf;
    const char* end = tempBuf + std::strlen(tempBuf);

    for (; it != end; ++it)
        ss << std::hex << unsigned(*it);

    unsigned result;
    ss >> result;

    std::cout << "Hex value: " << std::hex << result << std::endl;
    std::cout << "Decimal value: " << std::dec << result << std::endl;
}

#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char const *argv[])
{
    std::ifstream in("pads/24-02-2018:19:43:17/pad-0.txt");
    std::stringstream buffer;
    buffer << in.rdbuf();
    std::string contents(buffer.str());
    std::cout << contents << std::endl;
    return 0;
}

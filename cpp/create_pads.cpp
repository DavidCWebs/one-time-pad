#include "create_pads.hpp"

int main(int argc, char const *argv[])
{
    int createStatus;
    std::string newDir = getcwd() + "/pads";
    std::string baseDir = currentTimestamp();
    newDir = newDir + "/" + baseDir;

    createStatus = mkdir(newDir.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    std::cout << ((createStatus != 0) ? "FAIL" : "SUCCESS") << std::endl;

    std::string readme = newDir + "/README.md";
    std::ofstream file;
    file.open(readme);
    file <<
    "Multiple Lines\n"
    "==============\n"
    << currentTimestamp() << "\n" <<
    "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor.\n"
    "Incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.\n"
    "Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.\n" << std::endl;
    file.close();

    for (int i = 0; i < 5; i++) {
        std::stringstream padPath;
        padPath << newDir << "/pad-" << i << ".txt";
        std::string pad = padPath.str();
        std::string random = randomPrintableChars();
        std::ofstream file;
        file.open(pad);
        file << random << std::endl;
        file.close();
    }

    return 0;
}

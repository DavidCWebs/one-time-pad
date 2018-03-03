#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

class Encryptor
{
private:
    std::string plaintext;
    std::string key;

public:
    Encryptor();
    Encryptor(std::string inputPlaintext);
    void init();
    void init(std::string inputPlaintext);
    std::string stringToHex(const std::string& input);
    void setKey(std::string inputFile);
    void encrypt(std::string& ciphertext);
};

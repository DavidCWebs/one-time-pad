#include "Encryptor.hpp"

Encryptor::Encryptor() {}
Encryptor::Encryptor(std::string inputPlaintext)
    : plaintext(inputPlaintext)
{

}

void Encryptor::init()
{
}
void Encryptor::init(std::string inputPlaintext)
{
    plaintext = inputPlaintext;
}

std::string Encryptor::stringToHex(const std::string& input)
{
    std::stringstream hexStream;
    for (std::string::size_type i = 0; i < input.size(); ++i) {
        char c = input[i];
        hexStream << std::hex << std::uppercase << std::setfill('0') << std::setw (2) << (int)c;
    }
    return hexStream.str();
}

void Encryptor::setKey(std::string inputKeyFile)
{
    std::ifstream in(inputKeyFile);
    std::stringstream buffer;
    buffer << in.rdbuf();
    std::string contents(buffer.str());
    key = contents;
}

void Encryptor::encrypt(std::string& ciphertext)
{
    for (size_t i = 0; i < plaintext.length(); i++) {
        ciphertext.push_back(plaintext[i] ^ key[i]);
    }
}

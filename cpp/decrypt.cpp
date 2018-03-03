#include "string_utils.cpp"
#include "encrypt.hpp"
#include <fstream>

int main()
{
    std::vector<uint8_t> decryptedVector;
    std::string key, ciphertext;

    // Get Ciphertext
    std::cout << "Please input text to decrypt (hex format): ";
    std::getline(std::cin, ciphertext);

    // Decrypt
    std::string inputKeyFile = "pads/24-02-2018:19:43:17/pad-0.txt";
    std::ifstream in(inputKeyFile);
    std::stringstream buffer;
    buffer << in.rdbuf();
    std::string contents(buffer.str());
    // TODO Should key should be a hex string, so that printing is possible?
    key = ascii_to_hex_string(contents).substr(0, ciphertext.length());
    decryptedVector = xorIntVectors(hexStringToVector(ciphertext), hexStringToVector(key));

    // Output
    std::string decryptedString;
    for (uint8_t& c : decryptedVector) {
        decryptedString += c;
    }
    std::cout << "Decrypted message:\n" << decryptedString << std::endl;

    return 0;
}

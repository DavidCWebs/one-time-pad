#include "string_utils.cpp"
#include "encrypt.hpp"

int main()
{
    std::vector<uint8_t> decryptedVector;
    std::string key, ciphertext;

    // Get Ciphertext
    std::cout << "Please input text to decrypt (hex format): ";
    std::getline(std::cin, ciphertext);

    // Get key
    std::cout << "Please input decryption key (hex format): ";
    std::getline(std::cin, key);

    // Decrypt
    decryptedVector = xorIntVectors(hexStringToVector(ciphertext), hexStringToVector(key));

    // Output
    std::string decryptedString;
    for (uint8_t& c : decryptedVector) {
        decryptedString += c;
    }
    std::cout << "Decrypted message:\n" << decryptedString << std::endl;

    return 0;
}

#include "string_utils.hpp"
#include "encrypt.hpp"
#include "Encryptor.hpp"
#include <cstdio>

std::vector<int> int_array;
std::vector<int> ciphertext;
int main()
{
    std::string plaintext, ct;
    //key = "5L<ta";
    std::cout << "Please input text to encrypt: ";
    std::getline(std::cin, plaintext);
    Encryptor e(plaintext);
    e.setKey("pads/24-02-2018:19:43:17/pad-0.txt");
    e.encrypt(ct);
    std::cout << "ct: " << ct << std::endl;
    std::cout << e.stringToHex(ct) << std::endl;
    //xor_strings(plaintext, key, ciphertext);

    // std::string horLine = "";
    // for (size_t i = 0; i < 80; i++) horLine+= "─";
    // std::cout << horLine << std::endl;
    // std::cout << std:: left << std::setw(35) << "Hexified plaintext: " << ascii_to_hex_string(text) << std::endl;
    // std::cout << std:: left << std::setw(35) << "Hexified key: " << ascii_to_hex_string(key) << std::endl;
    // std::cout << std:: left << std::setw(35) << "Ciphertext: " << vectorToHexString(ciphertext) << std::endl;
    // std::cout << horLine << std::endl;

    return 0;
}

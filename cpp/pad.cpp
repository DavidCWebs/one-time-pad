#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "string_utils.cpp"

std::vector<int> int_array;
std::vector<int> ciphertext;
int main()
{
    std::string text;
    std::string key;
    key = "     ";
    long int num  = 0;
    std::cout << "Please input text to encrypt: ";
    std::getline(std::cin, text);
    xor_strings(text, key, ciphertext);
    std::cout << "Hexified: " << ascii_to_hex_string(text) << std::endl;

    // std::cout << "Encrypted: " << std::hex << std::uppercase << std::setfill('0') << std::setw (2) << (int)ciphertext << std::endl;
    // ascii_to_int_array(text, int_array);
    // for (size_t i = 0; i < int_array.size(); i++) {
    //     std::cout << "Returned:" << std::dec << int_array[i] << " | Char: " << (char)int_array[i] << std::endl;
    //     std::cout << "Hex:" << std::hex << int_array[i] << " | Char: " << (char)int_array[i] << std::endl;
    //     std::cout << "---" << std::endl;
    // }
    for (size_t i = 0; i < text.size(); i++) {
        std::cout << "plain: " << std::hex << std::uppercase << std::setfill('0') << std::setw (2) << (int)text[i] << ", " << (char)text[i];
        std::cout << " | cipher: " << std::hex << std::uppercase << std::setfill('0') << std::setw (2) << ciphertext[i] << ", " << (char)ciphertext[i] << std::endl;
    }
    return 0;
}

#include "string_utils.cpp"
#include "encrypt.hpp"
#include <cstdio>
// #include "create_pads.hpp"

std::vector<int> int_array;
std::vector<int> ciphertext;
int main()
{
    // create_pads()
    std::string text;
    std::string key;
    key = "5L<ta";
    std::cout << "Please input text to encrypt: ";
    std::getline(std::cin, text);
    xor_strings(text, key, ciphertext);
    std::string horLine = "";
    for (size_t i = 0; i < 80; i++) horLine+= "─";
    std::cout << horLine << std::endl;
    std::cout << std:: left << std::setw(35) << "Hexified plaintext: " << ascii_to_hex_string(text) << std::endl;
    std::cout << std:: left << std::setw(35) << "Hexified key: " << ascii_to_hex_string(key) << std::endl;
    std::cout << std:: left << std::setw(35) << "Ciphertext: " << vectorToHexString(ciphertext) << std::endl;
    std::cout << horLine << std::endl;

    // unsigned char c;
    // for (c = 32; c <= 255; c++) {
    //     char s = c;
    //     puts(s);
    // }



    return 0;
}

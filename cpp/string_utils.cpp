#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include "string_utils.h"

std::string ascii_to_hex_string(std::string input)
{
    std::string hex_out;
    std::stringstream hex_stream;
    for (std::string::size_type i = 0; i < input.size(); ++i)
    {
        char c = input[i];
        hex_stream << std::hex << std::uppercase << std::setfill('0') << std::setw (2) << (int)c;
    }
    return hex_stream.str();
}

void ascii_to_int_array(std::string input, std::vector<int> &int_array)
{
    for (std::string::size_type i = 0; i < input.size(); ++i)
    {
        int c = (int)input[i];
        int_array.push_back(c);
    }
    return;
}

void xor_strings(std::string plaintext, std::string key, std::vector<int> &ciphertext)
{
    for (std::string::size_type i = 0; i < plaintext.size(); ++i)
    {
        int c = (int)plaintext[i] ^ (int)key[i];
        ciphertext.push_back(c);
    }
    return;
}

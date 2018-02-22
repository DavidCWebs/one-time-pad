#include "string_utils.hpp"
std::vector<uint8_t> hexStringToVector(std::string inputHexString)
{
    std::vector<uint8_t> outputVector;
    for (size_t i = 0; i < inputHexString.length(); i+=2) {
        unsigned int x;
        std::stringstream ss;
        ss << std::hex << inputHexString.substr(i, 2);
        ss >> x;
        outputVector.push_back(x);
    }
    return outputVector;
}

std::string hexStringToASCII(std::string inputHexString)
{
    std::string outputString;
    for (size_t i = 0; i < inputHexString.length(); i+=2) {
        std::string x;
        std::stringstream ss;
        ss << inputHexString.substr(i, 2);
        ss >> x;
        outputString += x;
    }
    return outputString;
}

std::string vectorToHexString(std::vector<int> inputVector)
{
    std::stringstream outputStringStream;
    for(int& charCode : inputVector) {
        outputStringStream << std::hex << std::uppercase << std::setfill('0') << std::setw (2) << charCode;
    }
    return outputStringStream.str();
}

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

void xor_strings(std::string string1, std::string string2, std::vector<int> &resultVector)
{
    for (std::string::size_type i = 0; i < string1.size(); ++i)
    {
        int c = (int)string1[i] ^ (int)string2[i];
        resultVector.push_back(c);
    }
    return;
}

std::vector<uint8_t> xorIntVectors(std::vector<uint8_t> vec1, std::vector<uint8_t> vec2)
{
    std::vector<uint8_t> resultVector;
    for (size_t i = 0; i < vec1.size(); i++) {
        resultVector.push_back(vec1[i] ^ vec2[i]);
    }
    return resultVector;
}

#ifndef STRING_UTILS_H_
#define STRING_UTILS_H_
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
std::string hexStringToASCII(std::string inputHexString);
std::vector<uint8_t> xorIntVectors(std::vector<uint8_t> vec1, std::vector<uint8_t> vec2);
std::vector<uint8_t> hexStringToVector(std::string inputHexString);
std::string vectorToHexString(std::vector<int> inputVector);
std::string ascii_to_hex_string(std::string);
std::string hex_to_int(std::string);
void ascii_to_int_array(std::string input, std::vector<int> &int_array);
void xor_strings(std::string plaintext, std::string key, std::vector<int> &ciphertext);
#endif /* STRING_UTILS_H_ */

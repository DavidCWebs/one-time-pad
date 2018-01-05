#ifndef STRING_UTILS_H_
#define STRING_UTILS_H_

std::string ascii_to_hex_string(std::string);
std::string hex_to_int(std::string);
void ascii_to_int_array(std::string input, std::vector<int> &int_array);
void xor_strings(std::string plaintext, std::string key, std::vector<int> &ciphertext);

#endif /* STRING_UTILS_H_ */

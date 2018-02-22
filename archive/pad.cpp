#include <iostream>
#include <limits>
#include <algorithm>
#include <string>

int select_action(int default_choice);
int encrypt();
int decrypt();
std::string hex_string(std::string input);

int select_action(int default_choice)
{
    int validChoices[2] = {1,2};
    int choice;
    bool validChoice;
    while (true) {
        int x = 0;
        std::cout << "Please select an option:\n1) Encrypt\n2) Decrypt" << std::endl;
        std::cin >> choice;
        validChoice = std::any_of(std::begin(validChoices), std::end(validChoices), [&](int i)
        {
            return i == choice;
        });
        if (default_choice && choice == 0) {
            return default_choice;
        } else if (validChoice) {
            return choice;
        }
        std::cout << "----\nYou've entered an invalid selection.\nPlease enter either 1 or 2. Thanks.\n----" << std::endl;
    }
}

std::string hex_string(std::string input) {
    std::cout << "hex_string() plaintext: " << input << std::endl;
    return "XXX";
}

int encrypt() {
    std::string plaintext;
    std::cout << "Encryption begins..." << std::endl;
    std::cout << "Enter string to encrypt:" << std::endl;
    std::cin.ignore();
    getline(std::cin, plaintext);
    std::cout << "You entered: " << plaintext << std::endl;
    // # Turn plaintext string into hex string
    std::cout << hex_string(plaintext) << std::endl;
    // hs1 = hex_string(s1)
    // # Generate a random key
    // key = random_character_hex(len(s1))
    return 0;
}

int decrypt() {
    std::cout << "Decryption begins..." << std::endl;
    return 0;
}

int main(int argc, char const *argv[])
{
    int choice = 0;
    std::cout << "This program encrypts a message with a one time pad." << std::endl;
    choice = select_action(1);
    std::cout << "Choice made: " << choice << std::endl;

    if (choice == 1) {
        encrypt();
    } else if (choice == 2) {
        decrypt();
    }
    return 0;
}

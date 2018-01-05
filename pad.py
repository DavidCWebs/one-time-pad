#!/usr/bin/env python3
import random

def sxor_bytes(s1,s2):
    return bytes(x ^ y for x, y in zip(str.encode(s1), str.encode(s2)))

def xor_hex_string(hs1, hs2):
    output = str_to_hex(s1) ^ str_to_hex(s2)
    return to_hex(output)

def str_to_hex(s):
    return ''.join(hex(ord(c))[2:] for c in s)

def strxor(a, b):
    len_ = min(len(a), len(b))
    return "".join([chr(ord(x) ^ ord(y)) for (x, y) in zip(a[:len_], b[:len_])])

def hex_string_to_ascii_characters(s):
    return bytearray.fromhex(s).decode()

def xor_hex_strings(s1, s2):
    return "".join('{:02X}'.format(x ^ y) for (x, y) in zip(bytearray.fromhex(s1), bytearray.fromhex(s2)))

def hex_string(s):
    return ''.join('{:02X}'.format(ord(char)) for char in s)

def random_character_hex(n):
    # Create a list of randomly-selected integers
    ints = [random.randint(32, 125) for item in range(n)]
    # Create a hexadecimal string from the integers
    hs = ''.join(['{:02X}'.format(int) for int in ints])
    return hs

def main():
    s1 = input("Enter String 1:\n")
    # Turn plaintext string into hex string
    hs1 = hex_string(s1)
    # Generate a random key
    key = random_character_hex(len(s1))
    print("Key in text format:\n{}".format(hex_string_to_ascii_characters(key)))
    print("Plaintext in hex format:\n{}".format(hs1))
    print("Key in hex format:\n{}".format(key))
    print("Encrypted message (XOR strings, as hex string):\n{}".format(xor_hex_strings(hs1, key)))
    print("Encrypted message in text format:\n{}".format(hex_string_to_ascii_characters(xor_hex_strings(hs1, key))))

    print("Decryption\n--------")
    ds1 = input("Input ciphertext to decode:\n")
    ds2 = input("The key, in hex format:\n")
    xored = xor_hex_strings(ds1, ds2)
    print("Decrypted:\n{}".format(hex_string_to_ascii_characters(xored)))

if __name__ == '__main__':
    main()

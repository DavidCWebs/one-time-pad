#!/usr/bin/env python3
def hex_string_to_ascii_characters(s):
    return bytearray.fromhex(s).decode()

def main():
    s1 = input("Enter Hex String 1:\n")
    print("ASCII:\n{}".format(hex_string_to_ascii_characters(s1)))

if __name__ == '__main__':
    main()

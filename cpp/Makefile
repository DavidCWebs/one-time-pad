encrypt: encrypt.cpp encrypt.hpp string_utils.cpp string_utils.hpp src/Encryptor.hpp src/Encryptor.cpp
	g++ -I /home/david/Documents/learning-resources/hacking-ciphers/one-time-pad/cpp/src -o bin/encrypt -std=c++11 encrypt.cpp string_utils.cpp src/Encryptor.cpp

decrypt: decrypt.cpp encrypt.hpp string_utils.cpp string_utils.hpp
	g++ -o bin/decrypt -std=c++11 decrypt.cpp

create-pads: create_pads.cpp create_pads.hpp random.cpp random.hpp
	g++ -o bin/create-pads create_pads.cpp random.cpp -std=c++11

nonce: nonce.cpp
	g++ -o bin/nonce nonce.cpp -std=c++11

test: test.cpp
	g++ -o test test.cpp

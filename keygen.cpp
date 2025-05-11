#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>


void key_generator(long key_length) {
    srand(time(0));
    const std::string valid = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    char encrypted_key[key_length + 1];

    if (key_length <= 0) {
        std::cerr << "Argument length must be greater than zero." << std::endl;
        exit(1);
    }

    for (int i = 0; i < key_length; ++i) {
        int key = rand() % 27;
        encrypted_key[i] = valid[key];
    }
    encrypted_key[key_length] = '\0';
    std::cout << encrypted_key << std::endl;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << std::endl;
        return 1;
    }
    key_generator(atoi(argv[1]));
    return 0;
}

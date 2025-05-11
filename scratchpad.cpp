# include <iostream>

int timesTwo(const int number) {
    constexpr int two = 2;
    const int multiple = number * two;
    std::cout << number << " times two is: " << multiple << std::endl;
    return multiple;
}

void evenOrOdd(const int number) {
    if (number % 2 != 0) {
        std::cout << number << " is odd"  << std::endl;
        int doubled = timesTwo(number);

    } else {
        std::cout << number << " is even" << std::endl;
    }
}

void print(int j) {
    std::cout << "Hello, World!" << j << std::endl;
}

int main() {
    int n = 10;
    for (int i = 0; i <= n; ++i) {
        evenOrOdd(i);
    }

    int j = 3;
    for (int i = 0; i <= j; ++i) {
        print(i);
    }
    return 0;
}
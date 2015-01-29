#include <iostream>

bool is_adjacent(const unsigned char a, const unsigned char b);
bool power_2(const unsigned char c);

int main() {
    const unsigned char a, b;
    std::cout >> a >> b;
    std::cout << is_adjacent(a, b) << std::endl;
}

bool is_adjacent(const unsigned char a, const unsigned char b) {
    return power_2(a ^ b);
}

bool power_2(const unsigned char c) {
    return c != 0 && !(c & (c - 1));
}

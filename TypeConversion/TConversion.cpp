// 2.1.1

#include <iostream>

int main() {
    int n, r = 0, ld = 0;
    std::cout << "Введите N: "; std::cin >> n;
    ld = n;
    while (ld > 0) {
        r = r * 10 + ld % 10;
        ld /= 10;
    }
    (n == r) ? std::cout << "Палиндром." << std::endl : std::cout << "Не палиндром.";
    return 0;
}
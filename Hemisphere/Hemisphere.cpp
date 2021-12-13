// 1.5
#include <iostream>

int main()
{
    int a, b, c, d, e, f, g, h;
    
    // Ввод значений
    std::cout << "A: "; std::cin >> a;
    std::cout << "B: "; std::cin >> b;
    std::cout << "C: "; std::cin >> c;
    std::cout << "D: "; std::cin >> d;
    std::cout << "E: "; std::cin >> e;
    std::cout << "F: "; std::cin >> f;
    std::cout << "G: "; std::cin >> g;
    std::cout << "H: "; std::cin >> h;

    // Condition check (expr: ax + by + c = 0)
    
    ((a + b) * (c + d) > 0) ? std::cout << "Yes." : std::cout << "No.";

    return 0;
}
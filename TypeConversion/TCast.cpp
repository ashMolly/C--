// 2.1.2

#include <iostream>

int main() {
	double in;
	int k, n, r1 = 0, r2 = 0, c1, c2 = c1 = 0;

	std::cout << "Число: "; std::cin >> in;
	std::cout << "N, K: "; std::cin >> n >> k;
	
	in -= (int)in;
	c1 = int(in * 1000);
	c2 = ((in * 1000) - c1) * 1000;

	std::cout << "C1\tC2" << std::endl;
	std::cout << c1 << "\t" << c2 << std::endl;
	
	while (c1 > 0) { r1 += c1 % 10; c1 /= 10; }
	while (c2 > 0) { r2 += c2 % 10; c2 /= 10; }

	std::cout << "\nR1\tR2" << std::endl;
	std::cout << r1 << "\t" << r2 << std::endl;
	
	(r1 == r2) ? std::cout << "Равны." << std::endl : std::cout << "Не равны." << std::endl;

	return 0;
}
// 2.3

#include <iostream>
#include <bitset>
#include <vector>
#include <math.h>

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
  
    if (n % 2 == 0 || n % 3 == 0)
        return false;
  
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
  
    return true;
}

int main()
{
    int n, mp = 0;
    std::cout << "N: "; std::cin >> n;

    std::vector<int> allNumbers;
    std::vector<int> storePrimes;
    std::vector<int> binaryRecord;

    for (int i = 0; i < n; i++)
    {
        if (isPrime(i)) {
            storePrimes.push_back(i);
        }
    }

    for (int i = 0; i < storePrimes.size(); i++)
    {
        binaryRecord.push_back(8 - std::bitset<8>(storePrimes.at(i)).count());
        for (int s = 1; s < binaryRecord.size(); s++)
        {
            if (binaryRecord.at(s) < binaryRecord.at(s - 1))
            {
                mp = s - 1;
                break;
            }
        }
    }

    std::cout << "Простое число с наибольшим кол-вом нулей в двоичной записи: " << storePrimes.at(mp) << " [" << std::bitset<8>(storePrimes.at(mp)) << "]" << std::endl;

    return 0;
}
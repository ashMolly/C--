// 2.3

#include <iostream>
#include <bitset>
#include <vector>
#include <math.h>

int main()
{
    int n, mp = 0;
    std::cout << "N: "; std::cin >> n;

    std::vector<int> allNumbers;
    std::vector<int> storePrimes;
    std::vector<int> binaryRecord;

    for (int i = 2; i < n; i++)
    {
        allNumbers.push_back(i);
    }

    for (int i = 2; i < allNumbers.size() / 2; i++)
    {
        if (allNumbers.at(i - 2) % i == 0)
        {
            storePrimes.push_back(allNumbers.at(i - 2));
        }
    }

    for (int i = 0; i < storePrimes.size(); i++)
    {
        binaryRecord.push_back(std::bitset<8>(storePrimes.at(i)).count());
        for (int s = 1; s < binaryRecord.size() - 1; s++)
        {
            if (binaryRecord.at(s) > binaryRecord.at(s - 1))
            {
                mp = s;
            }
        }
    }

    std::cout << "Простое число с наибольшим кол-вом нулей в двоичной записи: " << storePrimes.at(mp) << std::endl;

    return 0;
}
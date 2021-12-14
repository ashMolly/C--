// 2.5

#include <iostream>
#include <string.h>
#include <math.h>

int slength(std::string str)
{
    int i = 0, cntr = 0;
    while (str[i] != '\0') i++;
    return i;
}

int main()
{
    int k, kCntr = 0;
    int search = 1;
    bool foundK = false;

    std::cout << "K: "; std::cin >> k;
    while(!foundK)
    {
        // 25-26: Нахождение числа последовательности, преобразование в строку и прибавление длины строки к счетчику
        std::string kV = std::to_string(search);
        // Функция slength(string) определяет длину строки (увеличение счетчика на 1 пока не достигнут нулевой символ или символ конца строки)
        kCntr += slength(kV);
        // Если счетчик больше (или равен) искомой позиции числа последовательности, вывод числа и завершение цикла
        if (kCntr >= k)
        {
            kCntr = kCntr - slength(kV);
            std::cout << "K-е число в последовательности: " << kV[k - kCntr - 1] << std::endl;
            std::cout << "Число: " << kV;
            foundK = true;
        }
        search *= 2; // Увеличиваем число в 2 раза (если счетчик не сработал)
    }

    return 0;
}
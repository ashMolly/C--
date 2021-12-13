// 2.4
#include <iostream>

int main()
{
    // Variables
    int
        seqSize,
        maxSeqCount = 0,
        seqCount = 0,
        nextValue = 0,
        currentValue = 0,
        prevValue = 0,
        itr = 0;

        std::cout << "Размер последовательности: "; std::cin >> seqSize;
        while (itr < seqSize)
        {
            currentValue = prevValue;
            prevValue = nextValue;
            std::cout << "[" << itr << " / " << seqSize << "] Введите число: "; std::cin >> nextValue;
            if (nextValue - prevValue == prevValue - currentValue) { seqCount += 1; maxSeqCount = seqCount; } else { maxSeqCount = seqCount; seqCount = 0; }
            itr += 1;
        }
        std::cout << "Максиммальная длина арифметической подпоследовательности: " << maxSeqCount + 1;
}
// 3.1

#include <iostream>
#include <string.h>
#include <time.h>

// Форматированный вывод массива
void printArray(int* array, int size)
{
    std::cout << "{ ";
    for (int i = 0; i < size; i++)
    {
        if (i == size - 1)
        {
            std::cout << *(array + i) << " }";
        } else {
            std::cout << *(array + i) << ", ";
        }
    }
}

int main()
{
    srand(time(NULL)); // Генерация новых случайных чисел

    const int N = 10, M = 15, K = N + M; // Инициализация размеров массивов А, B, C

    int A[N] = {0}, B[M] = {0}, C[K] = {0}; // 
    int defA[N] = {19, 17, 15, 1, 3, 5, 7, 9, 13, 11},
        defB[M] = {2, 6, 8, 4, 18, 16, 14, 10, 12, 25, 24, 22, 23, 20, 21};
    
    int select, replace;
    bool ccomp = false;
    
    enum Process
    {
        Random = 1,
        Init = 2,
        Keyboard = 3
    };

    Process p = Process::Random;
    std::cout << "1 - Заполнение массива случайными числами\n2 - Создание массива с данными при объявлении\n3 - Ввод данных в массив с клавиатуры\n\nВыбор: "; std::cin >> select;
    std::cout << std::endl << std::endl;
    switch(select)
    {
        case 1: p = Process::Random; break;
        case 2: p = Process::Init; break;
        case 3: p = Process::Keyboard; break;
        default: std::cout << "Error."; return -1;
    }

    switch(p)
    {
        case Process::Random:
        {
            for (int i = 0; i < K; i++) { (i >= N) ? B[i - N] = rand() % 100 : A[i] = rand() % 100; }
        }; break;
        case Process::Init:
        {
            memcpy(A, defA, sizeof(A));
            memcpy(B, defB, sizeof(B));
        }; break;
        case Process::Keyboard:
        {
            std::cout << "<-- A -->" << std::endl;
            for (int i = 0; i < N; i++) std::cin >> A[i];
            std::cout << "<-- B -->" << std::endl;
            for (int i = 0; i < M; i++) std::cin >> B[i];
        }; break;
        default: std::cout << "Error. (L42)"; break;
    }

    while (ccomp == false)
    {
        std::cout << std::endl << "<-- A -->" << std::endl;
        std::cout << "Исходный:\t\t"; printArray(A, N); std::cout << std::endl;
        
        for (int i = 0; i < N; i++)
        {
            for (int j = 1; j < N - i; j++)
            {
                if (A[j] < A[j - 1])
                {
                    replace = A[j - 1];
                    A[j - 1] = A[j];
                    A[j] = replace;
                }
            }
        }
        
        std::cout << "Сортированный:\t\t"; printArray(A, N); std::cout << std::endl << std::endl;
        std::cout << "<-- B -->" << std::endl;
        std::cout << "Исходный:\t\t"; printArray(B, M); std::cout << std::endl;

        for (int i = 0; i < M; i++)
        {
            for (int j = 1; j < M - i; j++)
            {
                if (B[j - 1] > B[j])
                {
                    replace = B[j];
                    B[j] = B[j - 1];
                    B[j - 1] = replace;
                }
            }
        }

        std::cout << "Сортированный:\t\t"; printArray(B, M); std::cout << std::endl << std::endl;
        // Заполнение массива С
        for (int i = 0; i < K; i++)
        {
            if (i >= N) { C[i] = B[i - N]; } else { C[i] = A[i]; }
        }

        std::cout << "<-- C -->" << std::endl;
        std::cout << "Исходный:\t\t"; printArray(C, K); std::cout << std::endl;
        // Сортировка массива С
        for (int i = 0; i < K; i++)
        {
            for (int j = 0; j < K - i; j++)
            {
                if (C[j + 1] < C[j])
                {
                    replace = C[j];
                    C[j] = C[j + 1];
                    C[j + 1] = replace;
                }
            }
        }
        std::cout << "Сортированный:\t\t"; printArray(C, K);

        ccomp = true;
    }

    return 0;
}
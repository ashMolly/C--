// 3.1

#include <iostream>
#include <string.h>

int main()
{
    const int N = 10, M = 15, K = N + M;

    int A[N] = {0}, B[M] = {0}, C[K] = {0};
    int defA[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19},
        defB[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 21, 22, 24, 25, 23};
    int select, replace;

    bool ccomp = false;
    
    enum Process
    {
        Random = 1,
        Init = 2,
        Keyboard = 3
    };

    Process p = Process::Random;
    std::cout << "u15: "; std::cin >> select;
    switch(select) { case 1: p = Process::Random; break; case 2: p = Process::Init; break; case 3: p = Process::Keyboard; break; default: std::cout << "Error."; break; }
    switch(p)
    {
        case Process::Random:
        {
            for (int i = 0; i < K; i++) { (i >= N) ? B[i] = rand() % 40 : A[i] = rand() % 30; }
        }; break;
        case Process::Init:
        {
            memcpy(A, defA, N);
            memcpy(B, defB, M);
        }; break;
        case Process::Keyboard:
        {
            for (int i = 0; i < K; i++) { (i >= N) ? std::cin >> B[i] : std::cin >> A[i]; }
        }; break;
        default: std::cout << "Error. (L42)"; break;
    }

    while (!ccomp)
    {
        for (int i = 0; i < N; i++)
        {
            if (A[i] > A[i + 1])
            {
                replace = A[i];
                A[i] = A[i + 1];
                A[i + 1] = replace;
            }
        }

        for (int i = 0; i < M; i++)
        {
            if (B[i] > B[i + 1])
            {
                replace = B[i];
                B[i] = B[i + 1];
                B[i + 1] = replace;
            }
        }
    }

    return 0;
}
// 2.2

#include <iostream>
#include <math.h>

int fact(int v)
{
    if (v == 0 || v == 1) { return 1; }
    else { return v * fact(v - 1); }
}

int main()
{
    double
        x0 = -4,
        xn = 6,
        dx =  0.5,
        x = x0,
        e = 0,
        y = 0;

    for (int i = 0; x < xn; i++)
    {
        e += pow(x, i) / fact(i);
        y += e - 1;
        std::cout << "Y: " << y << std::endl;
        x += dx;
    }

    return 0;
}
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

int x;

int getOperator()
{
    while (true)
    {
        printf("Введите значение х: ");
        scanf_s("%d", &x);
        return x;
    }
}

int factorial(int count)
{
    int fct = 1;
    for (int i = 1; i <= count; i++)
    {
        fct = fct * i;
    }
    return fct;
}

int solve(double radians, int n)
{
    long double d, e, a, b, c, result = 0;
    for (int y = 1; y < 100; y++)
    {
        d = (2 * y) - 1;
        e = y - 1;
        a = pow(-1, e);
        b = pow(radians, d);
        c = factorial(d);
        result += (a * b) / (long double)c;
        if ((result - sin(radians)) < e)
        {
            printf("S(x) - %Lf\n", result);
            printf("Исследуемое выражение отличается на заданную погрешность при n:" );
            return y;
        }
    }
    return 0;
}

int main()
{
    setlocale(0, "");
    getOperator();
    printf("%d", solve(x, 0));
    return 0;
}
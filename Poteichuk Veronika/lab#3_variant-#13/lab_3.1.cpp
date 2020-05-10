#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
//#include <cstdlib>
#include <time.h>

int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

void array(int n)
{
    int count = 0;
    int* arr = new int[n];
    int i = 0;
    while (n > 0)
    {
        arr[i] = n % 10;
        n /= 10;
        i++;
        count++;
    }
    printf("\n_____________________________________________");
    printf("\nNumber of digits in number: = %d\n", count);
    printf("_____________________________________________");
    int task = count + 1;
    int* array = new int[task];
    array[0] = count;
    for (int i=0; i<task; i++)
    {
        array[i+1] = arr[count-i-1];
        printf("\n%d. %d", i, array[i]);

    }
}

int main()
{
    srand( time(NULL));
    int value = rand() % 12 + 0;
    printf("Find the factorial of the number %d", value);
    factorial(value);
    int result = factorial(value);
    printf("\nFactorial of a number %d equals %d. \n", value, result);
    array(result);

    return 0;
}
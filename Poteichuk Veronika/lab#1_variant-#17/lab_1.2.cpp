
//#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <cmath>

int main()
{
    int number, cub_first, cub_second, cub_third, sum;

    for (int first = 1; first <= 9; first++)
        for (int second = 0; second <= 9; second++)
            for (int third = 0; third <= 9; third++)
            {
                cub_first = pow(first, 3);                                           //first * first * first
                cub_second = pow(second, 3);                                        //second* second* second;
                cub_third = pow(third, 3);                                         //third * third * third;
                sum = cub_first + cub_second + cub_third;
                number = first * 100 + second * 10 + third;

                if (number == sum)
                {
                        printf("A numbers equal to the sum of the cubes of its digits: %d\t", number);
                        printf("\n");
                };
            };
    return 0;
}


/*
#include "stdafx.h"
#include <stdio.h>
#include <conio.h>

main()
{
    int number, sum;

    for (int first = 1; first <= 9; first++)
        for (int second = 0; second <= 9; second++)
            for (int third = 0; third <= 9; third++)
            {
                sum = pow(first, 3)+pow(second, 3) + pow(thirt, 3);
                number = first * 100 + second * 10 + third;
                if (number == sum)
                {
                    printf("A numbers equal to the sum of the cubes of its digits: %d\t", number);
                    printf("\n");
                };
            };
    getch();
    return 0;
}
*/
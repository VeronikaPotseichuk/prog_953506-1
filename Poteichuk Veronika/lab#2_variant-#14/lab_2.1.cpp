#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

void areafunc(int R, double PI)
{
	system("cls");
	float ballarea = PI * pow(R, 2);
	printf("\nBall area: %f", ballarea);
}

void volumefunc(int R, double PI)
{
	system("cls");
	double ballvolume = 4  * PI * pow(R, 3) / 3;
	printf("\n\nBall volume: %f", ballvolume);

}

void edgefunc(int R)
{
	system("cls");
	float edgetetrahedron = (4 * R) / pow(6, 0.5);
	printf("\n\nEdge of the tetrahedron: %f", edgetetrahedron);
}

void sectionfunc(int R, int k, float PI)
{
	float sectionarea = PI * (pow(R, 2) - pow(k, 2));
	printf("\nCross-sectional area: %f\n", sectionarea);
}

void info()
{
	system("cls");
	char t;
	do 
	{
		printf("\nPress Enter to find out information about the author and the version of the program..");
		scanf_s("%c", &t);
	} while ((t = _getch()) != 13);
	printf("\n\nThe program was written by Veronika Poteychuk, 1st year student of the specialty 'Computer Science and Programming Technologies', 02.23.2020.");
}

void main()
{
	int R = 0, k = 0;
	const double PI = 3.1415;
	int choice;

	printf("Enter the radius of the ball: ");
	scanf_s("%d", &R);	
	R = abs(R);

	do
	{	
		system("cls");
		printf("Select operation..\n1. Ball area\n2. Ball volume\n3. Edge tetrahedron\n4. Section area\n5. Information\n6. Exit..\n\nChoice: ");
		scanf_s("%d", &choice);

		switch (choice)
		{
			case 1: areafunc(R, PI); _getch(); break;
			case 2: volumefunc(R, PI); _getch();  break;
			case 3:edgefunc(R); _getch(); break;
			case 4: 
			{	
				do
				{
					system("cls");
					printf("\n\nEnter the distance from the center of the ball: ");
					scanf_s("%d", &k);
				} while (abs(R) < abs(k));
				k = abs(k);
				Sleep(500);

				sectionfunc(R, k, PI); _getch(); break;
			}
			case 5: info(); Sleep(2000);  break;
		}
	} while (choice != 6);

}

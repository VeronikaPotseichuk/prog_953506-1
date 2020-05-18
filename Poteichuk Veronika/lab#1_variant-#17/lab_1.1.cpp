#include <cstdio>
#include <cmath>

void main()
{

	double tops = 0, arshin = 0, fathom = 0, verst = 0;
	int lenght = 0;
	
	printf("Enter lenght (in meters): ");
	scanf_s("%d", &lenght);
	//printf("\nlenght: %d", lenght);


	tops = lenght / 44.45 * 1000;
	printf("\nTranslation into Russian non-metric system: %f tops\n", tops);

	arshin = tops / 16;
	printf("Translation into Russian non-metric system: %f arshins\n", arshin);

	fathom = arshin / 3;
	printf("Translation into Russian non-metric system: %f fathom\n", fathom);

	verst = fathom / 500;
	printf("Translation into Russian non-metric system: %f versts\n", verst);

}



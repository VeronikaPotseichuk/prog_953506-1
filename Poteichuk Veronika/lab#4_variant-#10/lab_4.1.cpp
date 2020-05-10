//#include <windows.h>
#include <cstdio>
#include <stdio.h>

void morze(char x)
{
	if (x == 'A' || x == 'А') printf(".-");
	else if (x == 'B' || x == 'Б') printf("-...");
	else if (x == 'W' || x == 'В') printf(".--");
	else if (x == 'G' || x == 'Г') printf("--.");
	else if (x == 'D' || x == 'Д') printf("-..");
	else if (x == 'E' || x == 'Е' || x == 'Ё') printf(".");
	else if (x == 'V' || x == 'Ж') printf("...-");
	else if (x == 'Z' || x == 'З') printf("--..");
	else if (x == 'I' || x == 'И') printf("..");
	else if (x == 'J' || x == 'Й') printf(".---");
	else if (x == 'K' || x == 'К') printf("-.-");
	else if (x == 'L' || x == 'Л') printf(".-..");
	else if (x == 'M' || x == 'М') printf("--");
	else if (x == 'N' || x == 'Н') printf("-.");
	else if (x == 'O' || x == 'О') printf("---");
	else if (x == 'P' || x == 'П') printf(".--.");
	else if (x == 'R' || x == 'Р') printf(".-.");
	else if (x == 'S' || x == 'С') printf("...");
	else if (x == 'T' || x == 'Т') printf("-");
	else if (x == 'U' || x == 'У') printf("..-");
	else if (x == 'F' || x == 'Ф') printf("..-.");
	else if (x == 'H' || x == 'Х') printf("....");
	else if (x == 'C' || x == 'Ц') printf("-.-.");
	else if (x == 'Ч') printf("---.");
	else if (x == 'Ш') printf("----");
	else if (x == 'Q' || x == 'Щ') printf("--.-");
	else if (x == 'Ъ') printf(".--.-.");
	else if (x == 'Y' || x == 'Ы') printf("-.--");
	else if (x == 'X' || x == 'Ь') printf("-..-");
	else if (x == 'Э') printf("...-...");
	else if (x == 'Ю') printf("..--");
	else if (x == 'Я') printf(".-.-");
	else if (x == '1') printf(".----");
	else if (x == '2') printf("..---");
	else if (x == '3') printf("...--");
	else if (x == '4') printf("....-");
	else if (x == '5') printf(".....");
	else if (x == '6') printf("-....");
	else if (x == '7') printf("--...");
	else if (x == '8') printf("---..");
	else if (x == '9') printf("----.");
	else if (x == '0') printf("-----");
	else if (x == '.') printf(".-.-.-");
	else if (x == ',') printf("--..--");
	else if (x == ':') printf("---...");
	else if (x == '?') printf("..--..");
	else if (x == '\"' || x == '\'') printf(".----.");
	else if (x == '-') printf("-....-");
	else if (x == '/') printf("-..-.");
	else if (x == ';') printf("-.--.-");
	else if (x == ' ') printf("  ");
	else printf("?");
	printf(" ");
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char inputtr[80];
	printf("Write some string:\n");
	scanf_s("%s", inputtr, (unsigned)_countof(inputtr));
	printf("This string in the language of Morse:\n");
	for (int i = 0; i < strlen(inputtr); i++)
	{
		if ((inputtr[i] < 123 && inputtr[i] > 96) || (inputtr[i] < 256 && inputtr[i] > 223)) inputtr[i] -= 32;
		morze(inputtr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}


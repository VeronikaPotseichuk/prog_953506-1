//Морзянка. Вводимый с клавиатуры текст перевести в последовательность точек и тире с помощью азбуки Морзе.

#include <windows.h>
#include <cstdio>
#include <stdio.h>

void morze(char x)
{
	switch (x)
	{
	case'A': case'А': {printf(".-"); break; }
	case'B': case'Б': {printf("-..."); break; }
	case'W': case'В': {printf(".--"); break; }
	case'G': case'Г': {printf("--."); break; }
	case'D': case'Д': {printf("-.."); break; }
	case'E': case'Е': case'Ё': {printf("."); break; }
	case'V': case'Ж': {printf("...-"); break; }
	case'Z': case'З': {printf("--.."); break; }
	case'I': case'И': {printf(".."); break; }
	case'J': case'Й': {printf(".---"); break; }
	case'K': case'К': {printf("-.-"); break; }
	case'L': case'Л': {printf(".-.."); break; }
	case'M': case'М': {printf("--"); break; }
	case'N': case'Н': {printf("-."); break; }
	case'O': case'О': {printf("---"); break; }
	case'P': case'П': {printf(".--."); break; }
	case'R': case'Р': {printf(".-."); break; }
	case'S': case'С': {printf("..."); break; }
	case'T': case'Т': {printf("-"); break; }
	case'U': case'У': {printf("..-"); break; }
	case'F': case'Ф': {printf("..-."); break; }
	case'H': case'Х': {printf("...."); break; }
	case'C': case'Ц': {printf("-.-."); break; }
	case'Ч': {printf("---."); break; }
	case'Ш': {printf("----"); break; }
	case'Q': case'Щ': {printf("--.-"); break; }
	case'Ъ': {printf(".--.-."); break; }
	case'Y': case'Ы': {printf("-.--"); break; }
	case'X': case'Ь': {printf("-..-"); break; }
	case'Э': {printf("...-..."); break; }
	case'Ю': {printf("..--"); break; }
	case'Я': {printf(".-.-"); break; }

	case'1': {printf(".----"); break; }
	case'2': {printf("..---"); break; }
	case'3': {printf("...--"); break; }
	case'4': {printf("....-"); break; }
	case'5': {printf("....."); break; }
	case'6': {printf("-...."); break; }
	case'7': {printf("--..."); break; }
	case'8': {printf("---.."); break; }
	case'9': {printf("----."); break; }
	case'0': {printf("-----"); break; }

	case',': {printf("--..--"); break; }
	case'.': {printf(".-.-.-"); break; }
	case';': {printf("-.--.-"); break; }
	case':': {printf("---..."); break; }
	case'?': {printf("..--.."); break; }
	case'-': {printf("-....-"); break; }
	case'/': {printf("-..-."); break; }
	case' ': {printf(" "); break; }
	default: printf("?"); break;
	}
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


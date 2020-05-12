//Морзянка. Вводимый с клавиатуры текст перевести в последовательность точек и тире с помощью азбуки Морзе.

#include <windows.h>
#include <cstdio>
#include <stdio.h>

void morze(char x)
{
	switch (x)
	{
	case'A':case'a': case'А':case'а': {printf(".-"); break; }
	case'B':case'b': case'Б':case'б': {printf("-..."); break; }
	case'W':case'w': case'В':case'в': {printf(".--"); break; }
	case'G':case'g': case'Г':case'г': {printf("--."); break; }
	case'D':case'd': case'Д':case'д': {printf("-.."); break; }
	case'E':case'e': case'Е': case'е':case'Ё':case'ё': {printf("."); break; }
	case'V':case'v': case'Ж': case'ж': {printf("...-"); break; }
	case'Z':case'z': case'З': case'з': {printf("--.."); break; }
	case'I':case'i': case'И': case'и': {printf(".."); break; }
	case'J':case'j': case'Й': case'й': {printf(".---"); break; }
	case'K':case'k': case'К': case'к': {printf("-.-"); break; }
	case'L':case'l': case'Л': case'л': {printf(".-.."); break; }
	case'M':case'm': case'М': case'м': {printf("--"); break; }
	case'N':case'n': case'Н': case'н': {printf("-."); break; }
	case'O':case'o': case'О': case'о': {printf("---"); break; }
	case'P':case'p': case'П': case'п': {printf(".--."); break; }
	case'R':case'r': case'Р': case'р': {printf(".-."); break; }
	case'S':case's': case'С': case'с': {printf("..."); break; }
	case'T':case't': case'Т': case'т': {printf("-"); break; }
	case'U':case'u': case'У': case'у': {printf("..-"); break; }
	case'F':case'f': case'Ф': case'ф': {printf("..-."); break; }
	case'H':case'h': case'Х': case'х': {printf("...."); break; }
	case'C':case'c': case'Ц': case'ц': {printf("-.-."); break; }
	case'Ч':case'ч': {printf("---."); break; }
	case'Ш':case'ш': {printf("----"); break; }
	case'Q':case'q': case'Щ': case'щ': {printf("--.-"); break; }
	case'ъ': {printf(".--.-."); break; }
	case'Y':case'y': case'ы': {printf("-.--"); break; }
	case'X':case'x': case'ь': {printf("-..-"); break; }
	case'Э':case'э': {printf("...-..."); break; }
	case'Ю':case'ю': {printf("..--"); break; }
	case'Я':case'я': {printf(".-.-"); break; }

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


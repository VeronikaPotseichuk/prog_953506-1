//В одном файле дан исходный текст программы на языке С, в другом – словарь ключевых слов этого языка.Преобразовать текст, записав ключевые слова прописными буквами, а остальные – строчными.

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <ctype.h>

char* key_UP(char* buff, char(*keys)[20], int num_keys)
{
	char* outbuff = (char*)calloc(256, sizeof(char));
	char* test_key = (char*)calloc(20, sizeof(char));
	if (outbuff && test_key)
	{
		int numc = 0;

		//переписываем в выходную строку все небуквенные символы до первой буквы
		while (!isalpha(buff[numc]) && buff[numc] != '\0')
			outbuff[numc] = buff[numc++];

		//проверяем, является ли слово, встреченное в строке, ключевым
		while (buff[numc] != '\0')
		{
			bool iskey = false;
			int numctk = 0;
			int newnumc = numc;

			//заносим это слово в буфферную строку
			while (isalpha(buff[newnumc]))
			{
				test_key[numctk++] = buff[newnumc++];
			}
			test_key[numctk++] = '\n';
			test_key[numctk] = '\0';

			//проверяем совпадения с ключевыми словами
			for (int j = 0; j < num_keys; j++)
				if (!strcmp(test_key, keys[j]))
				{
					iskey = true;
					break;
				}

			//в зависимости от результата прошлого цикла посимвольно переписываем слово КАПСОМ или нет в выходную строку
			if (iskey)
			{
				while (isalpha(buff[numc]))
				{
					outbuff[numc] = (char)toupper(buff[numc]);
					numc++;
				}
			}
			else
			{
				while (isalpha(buff[numc]))
				{
					outbuff[numc] = (char)tolower(buff[numc]);
					numc++;
				}
			}

			//переписываем в выходную строку все небуквенные символы до первой буквы
			while (!isalpha(buff[numc]) && buff[numc] != '\0')
			{
				outbuff[numc] = buff[numc];
				numc++;
			}
		}
		outbuff[numc] = '\0';
		return outbuff;
	}
	else
	{
		printf("Memory error");
	}
	free(outbuff);
	free(test_key);
}

int main()
{
	char* buff;

	buff = (char*)calloc(256, sizeof(char));
	if (buff)
	{
		char keys[100][20];
		int num_keys = 0;
		FILE* inf, * outf, * key_words;

		//открываем файлы для чтения\записи
		if (fopen_s(&inf, "input.txt", "r")) printf("Error opening file input.txt.\n");
		else
		{
			fopen_s(&outf, "output.txt", "w");
			if (fopen_s(&key_words, "key_words.txt", "r")) printf("Error opening file key_words.txt.\n");
			else
			{
				//заносим в массив строк все ключевые слова
				while (fgets(buff, 256, key_words) != NULL)
				{
					strcpy_s(keys[num_keys], buff);
					num_keys++;
				}

				//извлекаем строки из входного файла и ищем в них ключевые слова
				while (fgets(buff, 256, inf) != NULL)
				{
					buff = key_UP(buff, keys, num_keys);
					fputs(buff, outf);
				}

				//закрываем файловые потоки
				fclose(key_words);
				printf("OK\n");
			}
			fclose(outf);
			fclose(inf);
			free(outf);
			free(key_words);
			free(inf);
		}
	}
	else printf("Memory error\n");
	free(buff);
	return 0;
}


//Разработать функции сравнения и копирования бинарного дерева

#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <locale>
#include <cstdio>

typedef struct Node
{
	int key;
	Node* left, * right;
} Node;
typedef Node* PNode;

//объявляем функции
int read();
bool DoesItEqual(PNode FirstTree, PNode SecondTree);
PNode CopyFrom(PNode OldTree);
PNode MakeTree(int data[], int from, int n);
void ShowTree(PNode Tree, int level, int vertical);
int* WriteMass(int& number);

//реализуем функции
int read()
{
	char c; //Переменная для хранения каждого введённого символа
	int num, i; //Переменная - вводимое число
	char str[9];
	bool correct;
	do
	{
		i = 0;
		correct = true;
		while (i < 8 && (c = _getch()) != 13 && c != ' ') //Проверка на границы и получение символа с клавиатуры
		{
			str[i++] = c;
			_putch(c);
		}
		for (int j = 0; j < i; j++)
		{
			if (!isdigit(str[j]))
			{
				printf("\nTry again\n");
				correct = false;
				break;
			}
		}
	} while (correct != true); //Если не число - ввод числа повторяется

	str[i] = '\0'; //Сформированную строку завершаем признаком окончания строки

	num = atoi(str); //Преобразуем строку в число
	return num;
}

bool DoesItEqual(PNode FirstTree, PNode SecondTree)
{
	bool equal;
	//если деревья пустые то возвращется true
	if (FirstTree == NULL && SecondTree == NULL) equal = true;
	else if (FirstTree != NULL && SecondTree != NULL)
	{
		//сравниваем ключи в корнях поддеревьев и рекурсивно вызываем сравнение их левых и правых поддеревьев
		equal = (FirstTree->key == SecondTree->key && DoesItEqual(FirstTree->left, SecondTree->left) && DoesItEqual(FirstTree->right, SecondTree->right));
	}
	//если одно поддерево пустое, а второе нет - возвращается false 
	else equal = false;
	return equal;
}

PNode CopyFrom(PNode OldTree)
{
	//создаём узел и копируем данные
	PNode CloneTree = new Node;
	CloneTree->key = OldTree->key;
	//левому и правому поддереву клона рекурсивно присваиваем указатели на клоны левого и правого поддеревьев копируемого дерева
	if (OldTree->left != NULL) CloneTree->left = CopyFrom(OldTree->left);
	else CloneTree->left = NULL;
	if (OldTree->right != NULL) CloneTree->right = CopyFrom(OldTree->right);
	else CloneTree->right = NULL;
	return CloneTree;
}

PNode MakeTree(int data[], int from, int n)
{
	//создаем сбалансированное дерево
	PNode Tree;
	int n1, n2;
	if (n == 0) return NULL;
	Tree = new Node;
	//ключу корня присваиваем значение среднего элемента массива
	Tree->key = data[from];
	n1 = n / 2;
	n2 = n - n1 - 1;
	//передаём левому поддереву значения массива до среднего элемента, правому - после
	Tree->left = MakeTree(data, from + 1, n1);
	Tree->right = MakeTree(data, from + n1 + 1, n2);
	return Tree;
}

void ShowTree(PNode Tree, int level, int vertical)
{
	if (Tree != NULL)
	{
		int clone = Tree->key;
		int sizekey = 0;
		int clonevertical = (vertical - ((vertical >> (level - 1)) << (level - 1))) + (1 << (level - 1));
		if (level > 1)
		{
			while (clonevertical != 1)
			{
				printf("          ");
				if (clonevertical - ((clonevertical >> 1) << 1) == 1)
				{
					printf("%c", 166);
				}
				else
				{
					printf(" ");
				}
				clonevertical = clonevertical >> 1;
			}
		}
		if (level != 0)
		{
			printf("          %c", 187);
		}
		printf("(%d)", Tree->key);
		while (clone != 0)
		{
			clone /= 10;
			sizekey++;
		}
		for (int i = 0; i < 10 - sizekey - 2 && (Tree->left != NULL || Tree->right != NULL); i++)
		{
			printf("%c", 151);
		}
		if (Tree->left != NULL || Tree->right != NULL)
		{
			printf("%c", 172);
		}
		printf("\n");
		ShowTree(Tree->left, level + 1, vertical + (1 << level));
		ShowTree(Tree->right, level + 1, vertical);
	}
}

int* WriteMass(int& number)
{
	printf("\nКоличество узлов в дереве (ориентация ЛКП): ");
	number = read();
	int* Mass = (int*)calloc(number, sizeof(int));
	printf("\nВведите числа, содержащиеся в узлах: ");
	for (int i = 0; i < number; i++)
	{
		Mass[i] = read();
		printf(" ");
	}
	return Mass;
}

//Удаление поддерева/всего дерева
void FreeMemory(PNode Tree)
{
	if (Tree != NULL)
	{
		FreeMemory(Tree->left);
		FreeMemory(Tree->right);
		free(Tree);
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	int choice, numOfFirst, numOfSecond;
	int* FirstMass, * SecondMass;
	PNode FirstTree = NULL, SecondTree = NULL;
	do
	{
		system("cls");
		printf("1. Ввести два дерева");
		printf("\n2. Сравнить деревья");
		printf("\n3. Копировать первое дерево во второе");
		printf("\n4. Копировать второе дерево в первое");
		printf("\n5. Вывести деревья");
		printf("\n6. Выход");
		printf("\nВаш выбор: ");
		choice = read();
		switch (choice)
		{
		case 1:
			system("cls");
			printf("Первое дерево:");
			FirstMass = WriteMass(numOfFirst);
			FirstTree = MakeTree(FirstMass, 0, numOfFirst);
			printf("\nВторое дерево:");
			SecondMass = WriteMass(numOfSecond);
			SecondTree = MakeTree(SecondMass, 0, numOfSecond);
			break;
		case 2:
			system("cls");
			if (DoesItEqual(FirstTree, SecondTree)) printf("\nДеревья равны.");
			else printf("Деревья не равны.\n");
			system("pause");
			break;
		case 3:
			system("cls");
			SecondTree = CopyFrom(FirstTree);
			printf("OK\n");
			system("pause");
			break;
		case 4:
			system("cls");
			FirstTree = CopyFrom(SecondTree);
			printf("\nOK\n");
			system("pause");
			break;
		case 5:
			system("cls");
			printf("Первое дерево:\n\n");
			ShowTree(FirstTree, 0, 0);
			printf("\nВторое дерево:\n\n");
			ShowTree(SecondTree, 0, 0);
			system("pause");
		}
	} while (choice != 6);
	FreeMemory(FirstTree);
	FreeMemory(SecondTree);
	return 0;
}


/*Задана очередь, указывающая порядок обработки одного из n стеков. 
Элементы очереди содержат номер обрабатываемого стека i (i <= n); признак выполняемого действия: ‘А’ – элемент из очереди добавляется в i - й стек, ‘D’ – из i - го стека удаляется элемент; данные (целые число d).
Разработать функцию обработки стеков в соответствии с заданной очередью.*/
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <cstdio>


typedef struct Stack
{
	Stack* next;
	int data;
} Stack;

typedef struct Queue
{
	Queue* next;
	Queue* prev;
	int data;
	int numOfStack;
	char action;
} Queue;

//объявляем функции
int read();
void PushStack(Stack** head, int value);
int PopStack(Stack** head);
bool IsEmptyStack(Stack** head);
void PushQueue(Queue** head, int value, char act, int nOS);
Queue* PopQueue(Queue** head);

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
		if (i == 0) correct = false;
	} while (correct != true); //Если не число - ввод числа повторяется

	str[i] = '\0'; //Сформированную строку завершаем нуль терминатором

	num = atoi(str); //Преобразуем строку в число
	return num;
}

void PushStack(Stack** head, int value)
{
	Stack* temp = (Stack*)malloc(sizeof(Stack));
	if (temp == NULL) printf("STACK_OVERFLOW");
	if (*head == NULL)
	{
		*head = temp;
		temp->data = value;
		temp->next = NULL;
	}
	else
	{
		temp->next = *head;
		temp->data = value;
		*head = temp;
	}
	free(temp);
}

int PopStack(Stack** head)
{
	if (*head != NULL)
	{
		int result = (*head)->data;
		*head = (*head)->next;
		return result;
	}
}

bool IsEmptyStack(Stack** head)
{
	if (*head == NULL) return true;
	else return false;
}

void PushQueue(Queue** head, int value, char act, int nOS)
{
	Queue* temp = (Queue*)malloc(sizeof(Queue));
	if (temp == NULL) printf("QUEUE_OVERFLOW");
	if (*head == NULL)
	{
		*head = temp;
		temp->data = value;
		temp->action = act;
		temp->numOfStack = nOS;
		temp->next = temp;
		temp->prev = temp;
	}
	else
	{
		temp->next = *head;
		temp->prev = (*head)->prev;
		(*head)->prev->next = temp;
		(*head)->prev = temp;
		temp->data = value;
		temp->action = act;
		temp->numOfStack = nOS;
	}
	free(temp);
}

Queue* PopQueue(Queue** head)
{
	if (*head != NULL)
	{
		Queue* res = *head;
		(*head)->prev->next = (*head)->next;
		(*head)->next->prev = (*head)->prev;
		*head = (*head)->next;
		return res;
	}
}

void DeleteStack(Stack ***head)
{
	free((**head)->next);
	free(**head);
	**head == NULL;
}

void DeleteQueue(Queue **head)
{
	free((*head)->next);
	free((*head)->prev);
	free(*head);
	*head = NULL;
}

int main()
{
	int n, numsOfQueue, numOfStack, data, i = 0;
	char action;
	printf("Write number of stacks: ");
	n = read();
	Stack** heads = (Stack**)calloc(n, sizeof(Stack*));
	for (int j = 0; j < n; j++)
	{
		heads[j] = NULL;
	}
	printf("\nWrite number of queue elements: ");
	numsOfQueue = read();
	Queue* headQueue = NULL;
	printf("\nStack || Action (A/D) || Data\n");

	while (i < numsOfQueue)
	{
		//считываем данные для элемента очереди
		numOfStack = read();
		printf(" ");
		do
		{
			action = _getch();
			if (action == 'D' || action == 'A')
			{
				_putch(action);
			}
		} while (action != 'A' && action != 'D');
		printf(" ");
		data = read();
		printf("\n");
		//проверяем на корректность
		if (numOfStack > 0 && numOfStack <= n)
		{
			PushQueue(&headQueue, data, action, numOfStack);
			i++;
		}
		else
		{
			printf("This stack doesn't exist\n");
		}
	}
	//добавляем элементы из очереди в стеки
	for (int j = 0; j < numsOfQueue; j++)
	{
		Queue* temp = PopQueue(&headQueue);
		numOfStack = temp->numOfStack;
		action = temp->action;
		Stack* thisStack = heads[j];
		if (action == 'A')
		{
			PushStack(&heads[numOfStack - 1], temp->data);
		}
		else
		{
			PopStack(&heads[numOfStack - 1]);
		}
	}
	//выводим информацию о результатах
	for (int j = 0; j < n; j++)
	{
		printf("\n%d stack: ", j + 1);
		while (!IsEmptyStack(&heads[j]))
		{
			printf("%d, ", PopStack(&heads[j]));
		}
	}
	printf("\n");
	system("pause");
	DeleteQueue(&headQueue);
	DeleteStack(&heads);
	return 0;
}


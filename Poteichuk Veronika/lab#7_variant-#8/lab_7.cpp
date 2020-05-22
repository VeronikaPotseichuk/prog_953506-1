/*�����������. ��������� ��� ��������� ��������. 
������� ���� ���������� �����-����� (������������ � ���� �������� ��������). 
� ������ �����-����� ������� �������� ������ � ��� ����. 
��� ����� �������� ���������� ������� ������ (������ �� ������� � 1 �����, ������ 0 � ������ �����). 
����� ������� ���� �������. 
����� ��������� ����� ���� ������� ������ ���������� ��������� ����������, ���� �� ���������� �����, � ���� ����, �� ������� �� �������� �����. 
������� �� ���� ���������� ����, ����� ������ ������� ������, ���������� ������ � ���������� ��� ���������� � ������� �������. */
// LabRab 7.cpp: ���������� ����� ����� ��� ����������� ����������.

#include "stdafx.h"
#include <iostream>
#include <conio.h>
typedef struct barcode
{
	int key;
	char name[80];
	int price;
	barcode* next;
	barcode* prev;
} barcode;
typedef barcode* BCode;

typedef struct creditcard
{
	int numofcard;
	int sale;
	creditcard* next;
	creditcard* prev;
} creditcard;
typedef creditcard* CCard;

//���������� �������
int ReadNumber();
int ReadBarCode();
int ReadNumProduct();
int ReadNumOfCard();
int Purchase(BCode headbarcode);
int UseCreditCard(int sum, CCard headcreditcard);
BCode ReadBarCodesFromFile(BCode headBC);
BCode AddNewBarCode(BCode head);
void ShowBarCode(BCode head);
BCode DeleteBarCode(BCode head);
void SaveBarCodesInFile(BCode headBC);
CCard ReadCreditCardsFromFile(CCard headCC);
CCard AddNewCreditCard(CCard head);
void ShowCreditCard(CCard head);
CCard DeleteCreditCard(CCard head);
void SaveCreditCardInFile(CCard headCC);

//�������� �� ����
int ReadNumber()
{
	char c; //���������� ��� �������� ������� ��������� �������
	int num, i; //���������� - �������� �����
	char str[10];
	bool correct;
	do
	{
		i = 0;
		correct = true;
		while (i < 9 && (c = _getch()) != 13 && c != ' ') //�������� �� ������� � ��������� ������� � ����������
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
	} while (correct != true); //���� �� ����� - ���� ����� �����������

	str[i] = '\0'; //�������������� ������ ��������� ��������� ��������� ������

	num = atoi(str); //����������� ������ � �����
	return num;
}

int ReadBarCode()
{
	char c; //���������� ��� �������� ������� ��������� �������
	int num, i; //���������� - �������� �����
	char str[7];
	bool correct;
	do
	{
		i = 0;
		correct = true;
		printf("Write 6-digit barcode: ");
		while (i < 6 && (c = _getch()) != 13) //�������� �� 13-��������� � ��������� ������� � ����������
		{
			str[i++] = c;
			_putch(c);
		}
		if (i != 6)
		{
			correct = false;
			printf("\nTry again\n");
		}
		else
		{
			for (int j = 0; j < 6; j++)
			{
				if (!isdigit(str[j]))
				{
					correct = false;
					printf("\nTry again\n");
					break;
				}
			}
		}
	} while (correct != true); //���� ����� �� 4-������� - ���� ����� �����������

	str[6] = '\0'; //�������������� ������ ��������� ��������� ��������� ������

	num = atoi(str); //����������� ������ � �����
	return num;
}

int ReadNumProduct()
{
	char c; //���������� ��� �������� ������� ��������� �������
	int num, i; //���������� - �������� �����
	char str[7];
	bool correct;
	do
	{
		i = 0;
		correct = true;
		printf("\nWrite num of product: ");
		while ((c = _getch()) != 13 && i < 6) //����� ������ �� ����� 6 ���� 
		{
			str[i++] = c;
			_putch(c);
		}
		str[i] = '\0';//�������������� ������ ��������� ��������� ��������� ������

		if (strlen(str) == 0)
		{
			return 1;
		}
		if (str[0] == '0' && strlen(str) == 1)
		{
			return -1;
		}
		else
		{
			//�������� �� ����� � ������
			for (int j = 0; j < i; j++)
			{
				if (!isdigit(str[j]))
				{
					correct = false;
					printf("\nTry again");
					break;
				}
			}
		}
	} while (correct != true); //���� ���� ������������ - ���� ����� �����������

	num = atoi(str); //����������� ������ � �����
	return num;
}

int ReadNumOfCard()
{
	char c; //���������� ��� �������� ������� ��������� �������
	int num, i; //���������� - �������� �����
	char str[5];
	bool correct;
	do
	{
		i = 0;
		correct = true;
		printf("Write 4-digit number of card: ");
		while (i < 4 && (c = _getch()) != 13) //�������� �� 4-��������� � ��������� ������� � ����������
		{
			str[i++] = c;
			_putch(c);
		}
		if (i != 4)
		{
			printf("\nTry again\n");
			system("cls");
			correct = false;
		}
		else
		{
			for (int j = 0; j < 4; j++)
			{
				if (!isdigit(str[j]))
				{
					printf("\nTry again\n");
					system("cls");
					correct = false;
				}
			}
		}
	} while (correct != true); //���� ����� �� 4-������� - ���� ����� �����������

	str[4] = '\0'; //�������������� ������ ��������� ��������� ��������� ������

	num = atoi(str); //����������� ������ � �����
	return num;
}

//�������
int Purchase(BCode headbarcode)
{
	int sum = 0;
	bool choiceproduct;
	FILE* outputHistory;
	fopen_s(&outputHistory, "history.txt", "a");
	
	printf("Do you want to add new item? Y/N\n");
	char choice = _getch();
	if (choice == 'Y' || choice == 'y') choiceproduct = true;
	else choiceproduct = false;
	while (choiceproduct)
	{
		int thisbarcode;
		thisbarcode = ReadBarCode();
		BCode current = headbarcode;
		while (current != NULL)
		{
			if (current->key == thisbarcode) break;
			current = current->next;
		}
		if (current == NULL)
		{
			printf("\nThis item doesn't exist");
		}
		else
		{
			int numproduct;
			numproduct = ReadNumProduct();
			if (numproduct == -1)
			{
				continue;
			}
			else
			{
				sum += (current->price) * numproduct;
				fprintf(outputHistory, "%s x %d = %d\n", &current->name, numproduct, (current->price) * numproduct);
			}
		}
		printf("\n\nDo you want to add new item? Y/N\n");
		choice = _getch();
		if (choice == 'Y' || choice == 'y') choiceproduct = true;
		else choiceproduct = false;
	} 
	fclose(outputHistory);
	return sum;
}

//���������� ��������� �����
int UseCreditCard(int sum, CCard headcreditcard)
{
	if (sum != 0)
	{
		FILE* outputHistory;
		fopen_s(&outputHistory, "history.txt", "a");
		printf("Have you some credit card? Y/N\n");
		char choice = _getch();
		if (choice == 'Y' || choice == 'y')
		{
			int j = 0;
			int numofcard = ReadNumOfCard();
			printf("\n");
			CCard current = headcreditcard;
			while (current != NULL)
			{
				if (numofcard == current->numofcard) break;
				current = current->next;
			}
			if (current == NULL)
			{
				printf("\nThe card with this number doesn't exist\n");
			}
			else
			{
				sum = (double)sum * (100.0 - (double)current->sale / 100.0);
				fprintf(outputHistory, "DISCOUNT %d%%\n", current->sale);
			}		
		}
		fprintf(outputHistory, "FINAL SUM %d\n", sum);
		fprintf(outputHistory, "end buyer\n");
		fclose(outputHistory);
	}
	system("pause");
	return sum;
}

//�������� � �����������
BCode ReadBarCodesFromFile(BCode headBC)
{
	int numberofbarcodes;
	FILE *inputBarCodes;
	fopen_s(&inputBarCodes, "barcode.txt", "r");
	if (!inputBarCodes)
	{
		printf("Can't open barcode.txt");
		return NULL;
	}
	fscanf_s(inputBarCodes, "%d", &numberofbarcodes);
	if (headBC == NULL)
	{
		headBC = new barcode;
		headBC->next = NULL;
		headBC->prev = NULL;
		fscanf_s(inputBarCodes, "%d%s%d", &(headBC->key), &(headBC->name), _countof(headBC->name), &(headBC->price));
		numberofbarcodes--;
	}
	BCode current = headBC;
	for(int i = 0; i < numberofbarcodes; i++)
	{
		int key;
		char name[80];
		int price;
		bool alreadyhave = false;
		fscanf_s(inputBarCodes, "%d%s%d", &key, &name, _countof(name), &price);
		BCode newcurrent = headBC;
		while (newcurrent != NULL)
		{
			if (newcurrent->key == key)
			{
				alreadyhave = true;
				break;
			}
			newcurrent = newcurrent->next;
		}
		if (alreadyhave == false)
		{
			BCode current = new barcode;
			current->next = headBC;
			current->prev = NULL;
			headBC->prev = current;
			headBC = current;
			current->key = key;
			strcpy_s(current->name, name);
			current->price = price;
		}
	}
	fclose(inputBarCodes);
	printf("OK\n");
	system("pause");
	return headBC;
}

BCode AddNewBarCode(BCode head)
{
	int key, price;
	char name[80];
	key = ReadBarCode();
	printf("\nName: ");
	scanf_s("%s", name, (unsigned)_countof(name));
	printf("Price: ");
	price = ReadNumber();
	if (head == NULL)
	{
		head = new barcode;
		head->next = NULL;
		head->prev = NULL;
		head->key = key;
		strcpy_s(head->name, name);
		head->price = price;
	}
	else
	{
		BCode current = new barcode;
		current->next = head;
		current->prev = NULL;
		head->prev = current;
		head = current;
		current->key = key;
		strcpy_s(current->name, name);
		current->price = price;
	}
	return head;
}

void ShowBarCode(BCode head)
{
	BCode current = head;
	if (current == NULL)
	{
		printf("List of barcodes is empty\n");
	}
	else
	{
		while (current != NULL)
		{
			printf("%d %s price: %d\n", current->key, &current->name, current->price);
			current = current->next;
		}
	}
}

BCode DeleteBarCode(BCode head)
{
	ShowBarCode(head);
	if (head == NULL)
	{
		system("pause");
		return head;
	}
	int deletekey = ReadBarCode();
	BCode current = head;
	while (current != NULL && current->key != deletekey)
	{
		current = current->next;
	}
	if (current == NULL)
	{
		printf("\nThis code doesn't exist or this tree is empty\n");
		system("pause");
		return head;
	}
	else if (current == head && head->next == NULL)
	{
		head = NULL;
	}
	else if (current == head)
	{
		head = head->next;
		head->prev = NULL;
	}
	else
	{
		if (current->prev != NULL)
			current->prev->next = current->next;
		if(current->next != NULL)
			current->next->prev = current->prev;
	}
	printf("\nOK\n");
	system("pause");
	return head;
}

void SaveBarCodesInFile(BCode headBC)
{
	int numberofbarcodes = 0;
	FILE* outputBarCode;
	fopen_s(&outputBarCode, "barcode.txt", "w");
	if (!outputBarCode)
	{
		printf("Can't open barcode.txt");
		return;
	}
	BCode current = headBC;
	while (current != NULL)
	{
		numberofbarcodes++;
		current = current->next;
	}
	fprintf_s(outputBarCode, "%d\n", numberofbarcodes);
	current = headBC;
	while (current != NULL)
	{
		fprintf_s(outputBarCode, "%d %s %d\n", current->key, current->name, current->price);
		current = current->next;
	}
	printf("OK\n");
	system("pause");
	fclose(outputBarCode);
}

//�������� �� ���������� �������
CCard ReadCreditCardsFromFile(CCard headCC)
{
	int numberofcards;
	FILE* inputCreditCard;
	fopen_s(&inputCreditCard, "creditcard.txt", "r");
	if (!inputCreditCard)
	{
		printf("Can't open creditcard.txt");
		return NULL;
	}
	fscanf_s(inputCreditCard, "%d", &numberofcards);
	if (headCC == NULL)
	{
		headCC = new creditcard;
		headCC->next = NULL;
		headCC->prev = NULL;
		fscanf_s(inputCreditCard, "%d%d", &(headCC->numofcard), &(headCC->sale));
		numberofcards--;
	}
	for (int i = 0; i < numberofcards; i++)
	{
		int numofcard;
		int sale;
		bool alreadyhave = false;
		fscanf_s(inputCreditCard, "%d%d", &numofcard, &sale);
		CCard newcurrent = headCC;
		while (newcurrent != NULL)
		{
			if (newcurrent->numofcard == numofcard)
			{
				alreadyhave = true;
				break;
			}
			newcurrent = newcurrent->next;
		}
		if (alreadyhave == false)
		{
			CCard current = new creditcard;
			current->next = headCC;
			current->prev = NULL;
			headCC->prev = current;
			headCC = current;
			current->sale = sale;
			current->numofcard = numofcard;
		}
	}
	fclose(inputCreditCard);
	printf("OK\n");
	system("pause");
	return headCC;
}

CCard AddNewCreditCard(CCard head)
{
	int numofcard, sale;
	numofcard = ReadNumOfCard();
	printf("\nSale: ");
	scanf_s("%d", &sale);
	if (head == NULL)
	{
		head = new creditcard;
		head->next = NULL;
		head->prev = NULL;
		head->sale = sale;
		head->numofcard = numofcard;
	}
	else
	{
		bool alreadyhave = false;
		CCard newcurrent = head;
		while (newcurrent != NULL)
		{
			if (newcurrent->numofcard == numofcard)
			{
				alreadyhave = true;
				break;
			}
			newcurrent = newcurrent->next;
		}
		if (alreadyhave == false)
		{
			CCard current = new creditcard;
			current->next = head;
			current->prev = NULL;
			head->prev = current;
			head = current;
			current->sale = sale;
			current->numofcard = numofcard;
		}
	}
	return head;
}

void ShowCreditCard(CCard head)
{
	CCard current = head;
	if (current == NULL)
	{
		printf("List of credit cards is empty\n");
	}
	else
	{
		while (current != NULL)
		{
			printf("Card %d, discount: %d\n", current->numofcard, current->sale);
			current = current->next;
		}
	}

}

CCard DeleteCreditCard(CCard head)
{
	ShowCreditCard(head);
	if (head == NULL)
	{
		system("pause");
		return head;
	}
	int deletecard = ReadNumOfCard();
	CCard current = head;
	while (current != NULL && current->numofcard != deletecard)
	{
		current = current->next;
	}
	if (current == NULL)
	{
		printf("\nThis card doesn't exist or this tree is empty\n");
		system("pause");
		return head;
	}
	else if (current == head && head->next == NULL)
	{
		head = NULL;
	}
	else if (current == head)
	{
		head = head->next;
		head->prev = NULL;
	}
	else
	{
		if (current->prev != NULL)
			current->prev->next = current->next;
		if (current->next != NULL)
			current->next->prev = current->prev;
	}
	printf("\nOK\n");
	system("pause");
	return head;
}

void SaveCreditCardInFile(CCard headCC)
{
	int numberofcards = 0;
	FILE* outputCreditCard;
	fopen_s(&outputCreditCard, "creditcard.txt", "w");
	if (!outputCreditCard)
	{
		printf("Can't open creditcard.txt");
		return;
	}
	CCard current = headCC;
	while (current != NULL)
	{
		numberofcards++;
		current = current->next;
	}
	fprintf_s(outputCreditCard, "%d\n", numberofcards);
	current = headCC;
	while (current != NULL)
	{
		fprintf_s(outputCreditCard, "%d %d\n", current->numofcard, current->sale);
		current = current->next;
	}
	printf("OK\n");
	system("pause");
	fclose(outputCreditCard);
}


int main()
{
	BCode headBC = NULL;
	CCard headCC = NULL;
	int choice;
	do
	{
		system("cls");
		printf("1. Read barcodes from file\n");
		printf("2. Add new barcode\n");
		printf("3. Show barcode\n");
		printf("4. Delete barcode\n");
		printf("5. Save barcodes in file\n");
		printf("--------------------------------\n");
		printf("6. Read credit cards from file\n");
		printf("7. Add new credit card\n");
		printf("8. Show credit cards\n");
		printf("9. Delete credit card\n");
		printf("10. Save credit cards in file\n");
		printf("--------------------------------\n");
		printf("11. Add new purchase\n");
		printf("--------------------------------\n");
		printf("12. Exit\n");
		printf("You choice: ");
		choice = ReadNumber();
		switch (choice)
		{
		case 1:
			system("cls");
			headBC = ReadBarCodesFromFile(headBC);
			break;
		case 2:
			system("cls");
			headBC = AddNewBarCode(headBC);
			break;
		case 3:
			system("cls");
			ShowBarCode(headBC);
			system("pause");
			break;
		case 4:
			system("cls");
			headBC = DeleteBarCode(headBC);
			break;
		case 5:
			system("cls");
			SaveBarCodesInFile(headBC);
			break;
		case 6:
			system("cls");
			headCC = ReadCreditCardsFromFile(headCC);
			break;
		case 7:
			system("cls");
			headCC = AddNewCreditCard(headCC);
			break;
		case 8:
			system("cls");
			ShowCreditCard(headCC);
			system("pause");
			break;
		case 9:
			system("cls");
			headCC = DeleteCreditCard(headCC);
			break;
		case 10:
			system("cls");
			SaveCreditCardInFile(headCC);
			break;
		case 11:
			system("cls");
			int sum;
			sum = Purchase(headBC);
			sum = UseCreditCard(sum, headCC);
			break;
		}
	} while (choice != 12);
    return 0;
}


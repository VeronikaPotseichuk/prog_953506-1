// LabRab 7.cpp: определяет точку входа для консольного приложения.

#include "stdafx.h"
#include "Functions.h"


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


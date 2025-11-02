#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char name[50];
int CNIC=0;
int productInfo[4][2] = {{50, 100}, {10, 200}, {20, 300}, {8, 150}}, totalBill=0, postDiscBill=0, promoApplied=0;

void customerInformation()
{
	printf("Customer Information\n-------------------------------\n");
	printf("Enter Customer Name: ");
	fgets(name, 50, stdin);
	name[strcspn(name, "\n")]='\0';
	printf("Enter Customer CNIC: ");
	scanf("%d", &CNIC);
	
	printf("Press ENTER to continue to the main program.");
	while(getchar()!='\n');
	getchar();
}

void displayInventory()
{
	int i, j;
	
	printf("Display Inventory\n----------------------------------------------------\n\n");
	printf("Product Code\t|Quantity In Stock\t|Price per Product\n----------------------------------------------------");
	
	for(i=0; i<4; i++)
	{
		printf("\n%d\t\t", i);
		for(j=0; j<2; j++)
		{
			printf("| %d\t\t\t", productInfo[i][j]);
		}
	}
	printf("\n----------------------------------------------------\n\nPress ENTER to return to the main menu.");
	
	while(getchar()!='\n');
	getchar();
}

void addItemToCart()
{
	int itemCode=0, quantity=0;
	
	printf("Add Item to Cart\n-------------------------------------------\n");
	printf("Enter item code: ");
	scanf("%d", &itemCode);
	printf("Enter quantity of the product to be sold: ");
	scanf("%d", &quantity);
	printf("\n------------------------------------------------\nPRODUCT %d INFORMATION\n------------------------------------------------\n", itemCode);
	printf("Product Code: %d\nQuantity in Stock: %d\nPrice per Product: %d\n\n", itemCode, productInfo[itemCode][0], productInfo[itemCode][1]);
	
	if(quantity>productInfo[itemCode][0]){
		printf("Invalid quantity amount. Returning to main menu..");
	}
	else{
		productInfo[itemCode][0] -= quantity;
		totalBill += (productInfo[itemCode][1]*quantity);
		printf("%d unit/s of Product %d sold. %d remaining in stock.\n", quantity, itemCode, productInfo[itemCode][0]);
	}
	
	printf("\n----------------------------------------------------\n\nPress ENTER to return to the main menu.");
	while(getchar()!='\n');
	getchar();
	
}

void displayTotalBill()
{
	char promo[20];
	
	printf("Display Total Bill\n----------------------------------------------------\n");
	printf("Total Bill: %d\n", totalBill);
	printf("Promocode for 25%% discount(if you don't have one, type anything else): ");
	scanf("%s", promo);
	if((strcmp(promo, "Eid2025")==0) && promoApplied==0){
		printf("25%% discount applied on your total bill");
		postDiscBill = totalBill * 0.75;
		printf("\nDiscounted Bill: %d", postDiscBill);
		promoApplied=1;
	}
	printf("\n----------------------------------------------------\n\nPress ENTER to return to the main menu.");
	while(getchar()!='\n');
	getchar();
		
}

void showInvoice()
{
	printf("Invoice\n----------------------------------------------------\n");
	printf("Customer Name: %s\nCustomer CNIC: %d, Customer Bill Before Discount: %d\nCustomer Bill After Discount: %d\n----------------------------------------------------\n", name, CNIC, totalBill, postDiscBill);
	printf("\n----------------------------------------------------\n\nPress ENTER to return to the main menu.");
	while(getchar()!='\n');
	getchar();
}

int main()
{
	customerInformation();
	
	int menu=0;
	
	while(menu!=5)
	{
		system("cls");
		printf("Supermarket Inventory Management System\n-------------------------------------------\n");
		printf("1) Display Inventory\n2) Add Item to Cart\n3) Display Total Bill\n4) Show Invoice\n5) Exit System\n-------------------------------------------\n\nEnter a number to carry out it's respective function: ");
		scanf("%d", &menu);	
		
		switch(menu)
		{
			case 1:
				system("cls");
				displayInventory();
				break;
			case 2:
				system("cls");
				addItemToCart();
				break;
			case 3:
				system("cls");
				displayTotalBill();
				break;
			case 4:
				system("cls");
				showInvoice();
				break;
			case 5:
				printf("Closing system.....");
				break;
			default:
				printf("Invalid input. Please enter a number from 1-5 only. Press ENTER to re-take input\n");
				while(getchar()!='\n');
				getchar();
				
				
		}
	}
	
	return 0;
}

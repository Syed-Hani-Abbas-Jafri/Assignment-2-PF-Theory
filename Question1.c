#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define uniqueBooks 100

int bookISBNs[uniqueBooks], bookQuantity[uniqueBooks];
float bookPrice[uniqueBooks];
char bookTitle[uniqueBooks][50];

void addNewBook()
{
	int contin=0, duplicate=0,i, j;
	
	printf("Add New Book\n------------------------------------------------\n");
	for(i=0; i<10; i++)
	{
		printf("Book %d ISBN: ", i+1);
		scanf("%d", &bookISBNs[i]);
		
		for(j=0; j<10; j++)//duplicate ISBN check
		{
			if(bookISBNs[i]==bookISBNs[j] && j!=i){
				printf("Duplicate ISBN found. Please re-enter the book ISBN.\n\n");
				i--;
				duplicate=1;
				break;
			}
			else{
				duplicate=0;
			}
		}
		
		if(duplicate==0){
			while(getchar() != '\n');
		
			printf("Book %d Title: ",i+1);
			fgets(bookTitle[i], 50, stdin);
			bookTitle[i][strcspn(bookTitle[i], "\n")] = '\0';
	
			printf("Book %d Price: ", i+1);
			scanf("%f", &bookPrice[i]);
			printf("Book %d Quantity Available: ", i+1);
			scanf("%d", &bookQuantity[i]);
			
			if(i<9){
				printf("\nWould you like to keep adding books?(1=Yes/0=No)");
				scanf("%d", &contin);	
			}
			
			
			if(contin!=1){
				printf("Exiting Add New Book..\n------------------------------------------------\n\n");
				break;
			}
			
			printf("\n------------------------------------------------\n\n");
		}	
	}
	printf("Press ENTER to return to the main menu.");
	while(getchar()!='\n');
	getchar();
}


void processSale()
{
	int ISBN=0, contin=1, bookIndex, i;
	
	printf("Process a Sale\n------------------------------------------------\n");
	while(contin==1)
	{
		int found=0;
		printf("Input book ISBN for sale processing: ");
		scanf("%d", &ISBN);
		
		for(i=0; i<uniqueBooks; i++)
		{
			if(ISBN==bookISBNs[i]){
				printf("Book ISBN found.\n");
				bookIndex=i;
				found=1;
				break;
			}
		}
		
		if(found==0){
			printf("Book ISBN not found. Please re-enter the book ISBN to process a sale.\n\n");
		}
		else{
			printf("\n------------------------------------------------\nBOOK %d INFORMATION\n------------------------------------------------\n", ISBN);
			printf("ISBN: %d\nTitle: %s\nPrice: %f\nQuantity: %d\n", ISBN, bookTitle[bookIndex], bookPrice[bookIndex], bookQuantity[bookIndex]);
			printf("Enter quantity to sell: ");
			int sellQuantity=0;
			scanf("%d", &sellQuantity);
			if(sellQuantity>bookQuantity[bookIndex]){
				printf("Invalid book quantity. Do not enter a quantity greater than the available amount.\n");
			}
			else{
				bookQuantity[bookIndex] -= sellQuantity;
				printf("%d copies of Book %d sold. %d copies remaining.\n", sellQuantity, ISBN, bookQuantity[bookIndex]);
				
				printf("\nWould you like to process another sale?(1=Yes/0=No): ");
				scanf("%d", &contin);	
			}
			
		}
	}
	printf("Exiting Process a Sale..\n------------------------------------------------\n\n\nPress ENTER to return to the main menu.");
	while(getchar()!='\n');
	getchar();
}

void lowStockReport()
{
	int bookIndex ,i;
	printf("Low Stock Report\n------------------------------------------------\n");
	
	for(i=0; i<uniqueBooks; i++)
	{
		if(bookQuantity[i]<5 && bookISBNs[i]!=0){
			printf("\n------------------------------------------------\nBOOK %d INFORMATION\n------------------------------------------------\n", bookISBNs[i]);
			printf("ISBN: %d\nTitle: %s\nPrice: %f\nQuantity: %d\n", bookISBNs[i], bookTitle[i], bookPrice[i], bookQuantity[i]);
		}
	}
	printf("Report Complete..\n------------------------------------------------\n\n\nPress ENTER to return to the main menu.");
	while(getchar()!='\n');
	getchar();
	
}

int main()
{
	int menuOption=0;
	
	while(menuOption!=4)
	{
		system("cls");
		printf("Liberty Books CLI Application\n------------------------------------------------\n");
		printf("\n------------------------------------------------\n1) Add New Book\n2) Process a Sale\n3) Generate Low-Stock Report\n4) Exit Program\n------------------------------------------------\nEnter a number from 1-4 to carry out it's respective operation: ");
		scanf("%d", &menuOption);
		
		switch(menuOption)
		{
			case 1:
				system("cls");
				addNewBook();
				break;
			case 2:
				system("cls");
				processSale();
				break;
			case 3:
				system("cls");
				lowStockReport();
				break;
			case 4:
				printf("\nEnding program operations..");
				break;
			default:
				printf("Invalid input\nEnter a number from 1-4 to carry out it's respective operation: ");
		}	
	}
	
	return 0;
}

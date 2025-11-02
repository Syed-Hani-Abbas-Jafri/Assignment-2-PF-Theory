#include <stdio.h>
#include <stdlib.h>

int main()
{
	int stackSize=0, menu=0, i, cellsOccupied=0;
	stackSize=programStart(stackSize);
	int stackArray[stackSize];
	
	//array initialization
	for(i=0; i<stackSize; i++)
	{
		stackArray[i]=0;
	}
	
	while(menu!=5)
	{
		system("cls");
		printf("Stack Simulation\n-----------------------------\n");
		printf("1)Push\n2)Pop\n3)Peek\n4)Display\n5)Exit\n-----------------------------\nEnter a value to execute it's respective function: ");
		scanf("%d", &menu);
		
		switch(menu)
		{
			case 1:
				cellsOccupied=push(stackArray, stackSize, cellsOccupied);
				break;
			case 2:
				cellsOccupied=pop(stackArray, cellsOccupied);
				break;
			case 3:
				peek(stackArray, cellsOccupied);
				break;
			case 4:
				displayElements(stackArray, stackSize);
				break;
			case 5:
				printf("Exiting program...");
				break;
			default:
				printf("Invalid input. Please enter a value between 1 and 5 only.");
				while(getchar()!='\n');
				getchar();
		}
	}
	
	return 0;
}

int push(int stack[], int size, int spaceOccupied)
{
	int num;
	size--;
	
	system("cls");
	printf("Push Element\n-----------------------------\n");
	
	if(spaceOccupied<=size && spaceOccupied>=0){
		printf("Enter a number to push into the stack: ");
		scanf("%d", &num);
		stack[spaceOccupied] = num;
		printf("Value entered successfully.");
		spaceOccupied++;	
	}
	else if(spaceOccupied<0){
		spaceOccupied=0;
		printf("Invalid index error fixed.");
	}
	else{
		printf("All stack spaces reserved");
	}
	
	printf("\n\n-----------------------------\nPress ENTER to return back to the main menu.");	
	while(getchar()!='\n');
	getchar();
	
	return spaceOccupied;
}

int pop(int stack[], int topMostIndex)
{
	system("cls");
	if(stack[topMostIndex-1]==32761 || topMostIndex<0){
		printf("No value present.") ;
	}
	else{
		printf("%d popped out of the stack.", stack[topMostIndex-1]);
		stack[topMostIndex-1]=0;
		topMostIndex--;
	}
	
	printf("\n-----------------------------\nPress ENTER to return back to the main menu.");	
	while(getchar()!='\n');
	getchar();
	
	return topMostIndex;
}

void peek(int stack[], int topMostIndex)
{
	system("cls");
	if(stack[topMostIndex-1]==32761){
		printf("No value present.");
	}
	else{
		printf("Top most element in the stack: %d", stack[topMostIndex-1]);	
	}
	
	printf("\n\n-----------------------------\nPress ENTER to return back to the main menu.");	
	while(getchar()!='\n');
	getchar();
}

void displayElements(int stack[], int size)
{
	int i;
	system("cls");
	printf("Display Elements\n-----------------------------\n");
	for(i=0; i<size; i++)
	{
		printf("%d\n", stack[i]);
	}
	
	printf("\n-----------------------------\nPress ENTER to return back to the main menu.");	
	while(getchar()!='\n');
	getchar();
}

int programStart(int size)
{
	printf("Enter desired stack size: ");
	scanf("%d", &size);
	return size;
}

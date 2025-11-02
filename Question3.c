
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define maxRows 25
#define maxCols 25
#define arbitrarySize 63

int mainMenu()
{
    system("cls");      // clearing the terminal screen
    printf("================================\n| \033[1;33mPower Grid Monitoring System\033[0m |\n================================\n\n\n");
    
    printf("[Main Menu]\n  [1] Update Sector Status\n  [2] Query Sector Status\n  [3] Run System Diagnostic\n  [4] Exit");
    
    // getting user input
    char userInput[arbitrarySize];        // abitrary size
    while (true)
    {
        printf("\nEnter an option [1-4]: ");
        fgets(userInput, sizeof(userInput), stdin);
        if   ((strlen(userInput) == 2) && (userInput[0] == '1' || userInput[0] == '2' || userInput[0] == '3' || userInput[0] == '4'))
        { return (userInput[0] - '0'); }        // char to int
        else 
        { printf("> [!] Enter either 1, 2, 3, or 4"); }
    }
}
void updateSectorStatus(int powerGrid[][maxCols])
{
    printf("\nEnter coordinates (row, col): ");
    int row, col;
    scanf(" %d %d", &row, &col);
    
    printf("Which status flag do you want to manipulate?\n   [1] Power Status\n   [2] Overload Warning\n   [3] Maintenance Required\n=> ");
    int statusFlag;
    scanf(" %d", &statusFlag);

    printf("How do you want to manipulate it?\n   [1] Set\n   [2] Clear\n=> ");
    int action;
    scanf(" %d", &action);

    switch(statusFlag)
    {
        case 1:     // power status
            if (action == 1) 
            { powerGrid[row][col] |= 1; printf("\n> Power Status was set"); }
            else
            { powerGrid[row][col] &= ~(1); printf("\n> Power Status was cleared"); }     // me rem em alhamdulillah :D 
            break;
        case 2:     // overload warning
            if (action == 1) 
            { powerGrid[row][col] |= 2; printf("\n> Overload Warning was set"); }
            else
            { powerGrid[row][col] &= ~(2); printf("\n> Overload Warning was cleared"); }     // me rem em alhamdulillah :D 
            break;
        case 3:     // maintenance required
            if (action == 1) 
            { powerGrid[row][col] |= 4; printf("\n> Maintenance Required was set"); }
            else
            { powerGrid[row][col] &= ~(4); printf("\n> Maintenance Required was cleared"); }     // me rem em alhamdulillah :D 
            break;
        default:
            printf("> [!] Error: No such status flag");
            break;
    }
}
void querySectorStatus(int powerGrid[][maxCols])
{
    printf("\nEnter coordinates (row, col): ");
    int row, col;
    scanf(" %d %d", &row, &col);

    printf("\nPowerGrid[%d][%d]\n> Power is %s\n> There is %s Overload Warning\n> Maintenance %s required",
            row, col,
            ((powerGrid[row][col] & 1) == 1)? "On" : "Off",
            ((powerGrid[row][col] & 2) == 2)? "an" : "NO",
            ((powerGrid[row][col] & 4) == 4)? "is" : "is NOT"  );
}
void runSystemDiagnostic(int powerGrid[][maxCols])
{
    int overLoaded = 0, requireMaintenance = 0;

    for (int row = 0; row < maxRows; row++)
    {
        for (int col = 0; col < maxCols; col++)
        {
            if  ((powerGrid[row][col] & 2) == 2) { overLoaded++; }
            if  ((powerGrid[row][col] & 4) == 4) { requireMaintenance++; }
        }
    }

    printf("\n[Diagnostic Summary]\n  > Overloaded Sectors: %d\n  > Sectors Requiring Maintenance: %d", overLoaded, requireMaintenance);
}
void pressEnterToContinue()
{
    char userInput[arbitrarySize];     // arbitray 63 length string
    printf("\n\n\nPress Enter to Continue: ");
    fgets(userInput, sizeof(userInput), stdin);
}
void emptyBuffer()
{
    for (int i = 0; i < 50; i++)    // arbitrary max count
    {
        if (getchar() == '\n'){ break; }
    }
}


int main()
{
    int powerGrid[maxRows][maxCols];
    for (int row = 0; row < maxRows; row++){ for (int col = 0; col < maxCols; col++){ powerGrid[row][col] = 1; } }          // initializing the powerGrid array with 1s (assuming power is on in each sector at the start)

    while (true)
    {
        switch(mainMenu())
        {
            case 1:
                updateSectorStatus(powerGrid);                             // calling the respective functions based upon user input
                break;
            case 2:
                querySectorStatus(powerGrid);                                   // calling the respective functions based upon user input
                break;
            case 3: 
                runSystemDiagnostic(powerGrid);
                break;
            case 4: 
                return 0;                                                // exits from the program if the user opted for 'exit'
        }

        // press enter to continue
        emptyBuffer();      // emptying buffer
        pressEnterToContinue();
    }
}


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int mainMenu()
{
    system("cls");      // clearing the terminal screen
    printf("===========================\n| \033[1;33mMessage Encoder/Decoder\033[0m |\n===========================\n\n\n");
    
    printf("[Main Menu]\n  [1] Encode Message\n  [2] Decode Message\n  [3] Exit");
    
    // getting user input
    char userInput[63];        // abitrary size
    while (true)
    {
        printf("\nEnter an option [1-3]: ");
        fgets(userInput, sizeof(userInput), stdin);
        if   ((strlen(userInput) == 2) && (userInput[0] == '1' || userInput[0] == '2' || userInput[0] == '3'))
        {
            switch(userInput[0])
            {
                case '1': return 1;
                case '2': return 2;
                case '3': return 3;
            }
        }
        else { printf("> [!] Enter either 1, 2, or 3"); }
    }
}
void getUserMessage(char type, char userMessage[], int messageSize)
{
    // gets a message from the user;    type = ('e' for encode) & ('d' for decode)
    printf("\n\n[%s Message]", (type == 'e')? "Encode" : "Decode");
    while (true)
    {
        printf("\nEnter the message to %s: ", (type == 'e')? "encode" : "decode");
        fgets(userMessage, messageSize, stdin);
        if (strlen(userMessage) == 1)           // the user just pressed enter, so the string contains '\n' only
        {
            printf("> [!] Please enter something");
            continue;
        }
        else
        {
            userMessage[strlen(userMessage) - 1] = '\0';        // setting the newline char, \n, to the null terminator, \0
            break;
        }
    }
}
void encodeMessage(char message[])
{
    // string reversal
    int len = strlen(message);
    char reversedMessage[len + 1];

    for (int i = 0; i < len; i++)
    { 
        reversedMessage[i] = message[len - 1 - i];
    }
    reversedMessage[len] = '\0';        // setting the end of the string to the null terminator
    

    // toggling the 2nd & 5th bit of the reversedMessage
    // toggling the 2nd and 5th bits means: XOR 18 (16 + 2) 
    char encodedMessage[len + 1];
    for (int i = 0; i < len; i++)
    {
        encodedMessage[i] = (char) (reversedMessage[i] ^ 18);     // XOR 18
    }
    encodedMessage[len] = '\0';


    printf("  > Original: [%s]\n  > Reversed: [%s]\n  > Encoded:  [%s]", message, reversedMessage, encodedMessage);
}
void decodeMessage(char message[])
{
    // untoggling the 2nd & 5th bit of the message
    int len = strlen(message);
    char decodedMessage[len + 1];
    for (int i = 0; i < len; i++)
    {
        decodedMessage[i] = (char) (message[i] ^ 18);
    }
    decodedMessage[len] = '\0';


    // string reversal of the decodedMessage
    char reversedMessage[len + 1];

    for (int i = 0; i < len; i++)
    { 
        reversedMessage[i] = decodedMessage[len - 1 - i]; 
    }
    reversedMessage[len] = '\0';        // setting the end of the string to the null terminator
    

    printf("  > Original: [%s]\n  > Decoded: [%s]\n  > Reversed: [%s]", message, decodedMessage, reversedMessage);
}
void pressEnterToContinue(char buffer[])
{
    char userInput[63];     // arbitray 63 length string
    printf("\n\n\nPress Enter to Continue: ");
    fgets(userInput, sizeof(userInput), stdin);
}

int main()
{
    char userInput[63];

    while (true)
    {
        switch(mainMenu())
        {
            case 1:
                getUserMessage('e', userInput, sizeof(userInput));       // getting the message from the user
                encodeMessage(userInput);                                  // calling the respective functions based upon user input
                break;
            case 2:
                getUserMessage('d', userInput, sizeof(userInput));       // getting the message from the user
                decodeMessage(userInput);                                  // calling the respective functions based upon user input
                break;
            case 3: return 0;                                                // exits from the program if the user opted for 'exit'
        }

        // press enter to continue
        pressEnterToContinue(userInput);         // reusing the userInput string since its contents no use now
    }
}


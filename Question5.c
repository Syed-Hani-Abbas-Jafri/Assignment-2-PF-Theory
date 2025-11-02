/*
    Question No. 5

    TCS (Tranzum Courier Service), one of Pakistan’s leading logistics companies, operates a network
    of dispatch centers and delivery riders spread across multiple cities. The dispatch center in Karachi
    coordinates daily deliveries and pickups by sending out route instructions, tracking updates, and
    sensitive customer information to its field riders.
    However, these messages are often transmitted through unsecured digital channels — meaning
    that if someone intercepts the message, they could view addresses, package IDs, or delivery routes.
    To enhance security without the need for expensive encryption systems, TCS decided to introduce
    a lightweight command-line tool that can quickly encode and decode text messages using a simple
    but consistent algorithm.

    The goal of this project is to design and develop a simple C-based command-line utility that allows
    dispatch officers and riders to:
        • Encode ordinary text messages into a coded format before transmission.
        • Decode received coded messages back into readable text.
    The encoding process must be reversible, ensuring no loss of information. The tool is intended for
    internal communication, not for high end cryptographic security, but for basic confidentiality and
    tamper resistance.
    
    Encoding Algorithm:
    When a dispatcher types a plain text message (e.g., "Rider ready for delivery"), the program applies
    the following two-step transformation:
    1. Reversal Step
        • The entire message string is reversed character by character.
        • Example: "Rider ready for delivery" → "yreviled rof ydaer rediR"
    2. Bit Toggling Step
        • Each character in the reversed string is converted to its binary representation (ASCII
        value).
        • Then, the program toggles the 2nd and 5th bits of this value.
        Toggling means: if the bit is 1, make it 0; if it’s 0, make it 1.
        • The modified binary value is converted back to a new encoded character.
        • This creates a transformed message that looks like random symbols or gibberish to
        anyone intercepting it.
    After these steps, the encoded message is displayed and ready to be sent securely over text or radio.

    Decoding Algorithm
    On the receiver’s side (the delivery rider’s device), the decoding process must perfectly reverse
    the encoding.
    The decoding algorithm applies the same steps in reverse order:
    1. Bit Reversal (Untoggling):
        • The program takes the encoded text and toggles the 2nd and 5th bits of each character
        again.
        • Since toggling twice restores the original bits, this effectively undoes the first
        transformation.
    2. String Reversal:
        • The resulting string is then reversed again to restore the original order of characters.
        After these two steps, the original message text (e.g., "Rider ready for delivery") is recovered and
        displayed on screen.

    Program Flow
    The program follows an interactive command-line flow for ease of use by dispatch staff:
        1. Display a simple menu:
            • Encode Message
            • Decode Message
            • Exit
        2. Based on the user’s choice:
            • The program asks for the message input.
            • It then calls the appropriate function:
            • void encodeMessage(char message[])
            • void decodeMessage(char message[])
            • Each function performs its respective operation using string and bitwise logic.
        3. The result is displayed back on screen
        4. The user can continue encoding/decoding multiple messages until they choose to exit.

*/

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

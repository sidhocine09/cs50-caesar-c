#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool allDigits(string input);
void handle(string input, int key);
void shiftletter(char input, int key);

int main(int argc, string argv[])
{
    // Checks that there is only 1 command-line argument and that the key is an integer
    if (argc != 2 || !allDigits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        // Converts the string command-line argument into an int named "key"
        int key = atoi(argv[1]);
        // Prompts for plaintext
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        handle(plaintext, key);
        printf("\n");
    }
}

// Checks if the command-line argument for the key is an integer
bool allDigits(string input)
{
    // "Count" keeps track of the number of chars that are not digits
    int count = 0;
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (isdigit(input[i]) == false)
        {
            count++;
        }
    }
    // Returns "true" if the number of non-digit chars is 0
    return count == 0;
}

// Handles characters in plaintext, directing letters to the "shift" function
void handle(string input, int key)
{
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        // Directs letters to the "shift" function
        if (isalpha(input[i]))
        {
            shiftletter(input[i], key);
        }
        // Prints non-letters as is
        else
        {
            printf("%c", (input[i]));
        }
    }
}

void shiftletter(char input, int key)
{
    // Converts the char into an int so that A (or a) = 0, etc.
    int convertedplain = toupper(input) - 65;
    // Shifts the int value of char by the key value, rotating through alphabet
    int convertedcipher = ((convertedplain + key) % 26) + 65;
    // Make the case correct, based on plaintext case, and prints cipher char
    if (islower(input))
    {
        printf("%c", tolower(convertedcipher));
    }
    else
    {
        printf("%c", toupper(convertedcipher));
    }
}

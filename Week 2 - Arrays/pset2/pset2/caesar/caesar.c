#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //Checking command-line arguments
    if (argc != 2)
    {
        printf("Missing command-line argument\n");
        return 1;
    }
    
    //Checking if argument consists of only digits
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    
    //Getting plaintext from user 
    string plaintext = get_string("Plaintext: ");
    
    //Converting the command-line argument from string to int
    int k = atoi(argv[1]);
    
    printf("Ciphertext: ");
    
    //Enciphering each character by using the key 'k'
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char p = plaintext[i];
        if (isalpha(p))
        {
            if (islower(p))
            {
                printf("%c", (p + k - 'a') % 26 + 'a');
            }
            else if (isupper(p))
            {
                printf("%c", (p + k - 'A') % 26 + 'A');
            }
        }
        else
        {
            printf("%c", p);
        }
    }
    printf("\n");
    
    return 0;

}
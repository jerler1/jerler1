#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    //validating the key
    //if no key was given causes error
    if (argc == 1)
    {
        printf("Please input ./substitution.c KEY.\n");
        return 1;
    }
    //if more than one input was given causes error
    if (argc > 2)
    {
        printf("Please input one command line argument.\n");
        return 1;
    }
    int n = strlen(argv[1]);
    //if key is less than 26 causes error
    if (n != 26)
    {
        printf("Key needs to be 26 letters.\n");
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        //if key has non-alphabet letters ie numbers causes error
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Key must be letters.\n");
            return 1;
        }
    }
    //if key has duplicate letters causes error
    for (int k = 0; k < n; k++)
    {
        for (int j = 0; j < n; j++)
        {
            if (argv[1][k] == argv[1][j] && k != j)
            {
                printf("No duplicate letters!\n");
                return 1;
            }
        }
    }
    //storing the key in an array IF they key is given in uppercase it's being forced into lowercase
    char key[26];
    for (int u = 0; u < n; u++)
    {
        if (isupper(argv[1][u]) != 0)
        {
            argv[1][u] = argv[1][u] + 32;
        }
        key[u] = argv[1][u];
    }
    //getting the user to input a string and store it in plaintext
    string plaintext = get_string("Please input what you want to encipher: ");
    printf("plaintext: ");
    printf("%s\n", plaintext);
    //making a normal alphabet string
    string abc = "abcdefghijklmnopqrstuvwxyz";
    printf("ciphertext: "); //created a cipheretext string and then am performing the substitution
    int ptextlen = strlen(plaintext);
    for (int s = 0; s < ptextlen; s++)
    {
        if (isspace(plaintext[s]) != 0)
        {
            printf("%c", plaintext[s]);
        }
        if (isdigit(plaintext[s]) != 0)
        {
            printf("%c", plaintext[s]);
        }
        for (int j = 0; j <= 25; j++)
        {
            if (plaintext[s] == abc[j] || plaintext[s] == abc[j] - 32)
            {
                if (isupper(plaintext[s]) != 0)
                {
                    key[j] = key[j] - 32;
                    printf("%c", key[j]);
                    key[j] = key[j] + 32;
                }
                else if (islower(plaintext[s]) != 0)
                {
                    printf("%c", key[j]);
                }
            }
        }
    }
    printf("\n");
    return 0;
}
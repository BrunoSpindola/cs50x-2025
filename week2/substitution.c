#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_alpha(string s);
char encipher(char c, string k);

int main(int argc, string argv[])
{
    if (argc != 2 || !only_alpha(argv[1]))
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    string key = argv[1];
    string cipher = malloc(strlen(plaintext) + 1);

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        cipher[i] = encipher(plaintext[i], key);
    }

    printf("ciphertext: %s\n", cipher);
}

bool only_alpha(string s)
{
    // check have 26 characters
    int len = strlen(s);
    if (len == 26)
    {
        for (int i = 0; i < len; i++)
        {
            if (!isalpha(tolower(s[i])))
            {
                printf("Key must only contain alphabetic characters.\n");
                return false;
            }
        }

        for (int j = 0; j < len; j++)
        {
            for (int k = j + 1; k < len; k++)
            {
                if (tolower(s[j]) == tolower(s[k]))
                {
                    printf("Key must not contain repeated characters.\n");
                    return false;
                }
            }
        }
        return true;
    }
    else
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }
}

char encipher(char c, string k)
{
    char letter;
    if (isupper(c))
    {
        return letter = toupper(k[c - 'A']);
    }
    else if (islower(c))
    {
        return letter = tolower(k[c - 'a']);
    }
    else
    {
        return c;
    }
}

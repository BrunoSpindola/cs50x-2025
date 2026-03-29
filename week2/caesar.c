#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate(char p, int k);

int main(int argc, string argv[])
{

    // garantir que meu programa está aceitando apenas uma linha de comando
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");
    string ciphertext = malloc(strlen(plaintext) + 1);

    for (int j = 0, n = strlen(plaintext); j < n; j++)
    {
        ciphertext[j] = rotate(plaintext[j], key);
    }

    printf("ciphertext: %s\n", ciphertext);
}

// coverter argv[1] de string para int
bool only_digits(string s)
{

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char p, int k)
{
    if (islower(p))
    {
        return ((p - 'a' + k) % 26) + 'a';
    }
    else if (isupper(p))
    {
        return ((p - 'A' + k) % 26) + 'A';
    }
    else
    {
        return p;
    }
}

#include <cs50.h>
#include <math.h>
#include <stdio.h>

int len(long int);

int main(void)
{
    // Variables
    long int number = 0;

    // condição para pegar a varíavel number
    do
    {
        number = get_long("Number: ");
    }
    while (number < 0);

    long int size = len(number);
    long int invert_number[size];
    long int original_number = number;
    int luhn = 0;

    // luhn algorithm
    for (int i = 0; i < size; i++)
    {
        int product = 0;
        // get the last number
        int digit = number % 10;
        number /= 10;

        if (i % 2 == 1)
        {
            product = 2 * digit;
            if (product > 9)
            {
                luhn += product / 10 + product % 10;
            }
            else
            {
                luhn += product;
            }
        }
        else
        {
            luhn += digit;
        }
    }

    // verifica se o utlimo dígito da soma é igual 10
    if (luhn % 10 == 0)
    {
        long int first = original_number / (long int) pow(10, (size - 1));
        long int two_first = original_number / (long int) pow(10, (size - 2));

        if ((two_first == 34 || two_first == 37) && size == 15)
        {
            printf("AMEX\n");
        }
        else if ((two_first >= 51 && two_first <= 55) && size == 16)
        {
            printf("MASTERCARD\n");
        }
        else if (first == 4 && (size == 13 || size == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int len(long int n)
{
    int cont = 0;
    while (n > 0)
    {
        n /= 10;
        cont++;
    }

    return cont;
}

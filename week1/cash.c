#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Variables
    int cash = 0;
    int change_owed = 0;

    // get user infomation if the value is greater than zero
    do
    {
        // Put an input function to get the value in a variable called 'cash'
        cash = get_int("Change owed: ");
    }
    while (cash < 0);

    // We can just give change with 25 quarter cents, 10 cent coins, 5 cent coins and 1 cent coin
    // first: do it in a loop where it should continue until don't be grater than zero (cash > 0)
    while (cash > 0)
    {
        // verify if the variable cash are divisible by 25
        if ((cash / 25) > 0)
        {
            cash = cash - 25;
            change_owed++;
        }
        // verify if the variable cash are divisible by 10
        else if ((cash / 10) > 0)
        {
            cash = cash - 10;
            change_owed++;
        }
        // verify if the variable cash are divisible by 5
        else if ((cash / 5) > 0)
        {
            cash = cash - 5;
            change_owed++;
        }
        // verify if the variable cash are divisible by 1
        else
        {
            cash = cash - 1;
            change_owed++;
        }
    }

    printf("%i\n", change_owed);
}

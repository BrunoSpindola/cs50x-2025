#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int score_calculator(string word1);

int main(void)
{
    // get strings
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    // Calculate scores
    int score1 = score_calculator(player1);
    int score2 = score_calculator(player2);

    // Print Winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int score_calculator(string word)
{
    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    int sum = 0;

    // Check score1
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // If the letter is upper we subtract the equivalent value of the letter to detect what is
        // the position at the 'points' array
        if (isupper(word[i]))
        {
            sum += points[word[i] - 'A'];
        }
        // If the letter is lower we subtract the equivalent value of the letter to detect what is
        // the position at the 'points' array
        else if (islower(word[i]))
        {
            sum += points[word[i] - 'a'];
        }
    }
    return sum;
}

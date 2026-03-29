#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);

int main(void)
{
    // input string
    string text = get_string("Text: ");

    // check number of letters
    int num_letters = count_letters(text);
    int num_words = count_words(text);
    int num_sentences = count_sentences(text);

    float L = ((float) num_letters / (float) num_words) * 100;
    float S = ((float) num_sentences / (float) num_words) * 100;

    // printf("%f\n", L);
    // printf("%f\n", S);

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string s)
{
    int sum_l = 0;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // Check if the content in the array is an alphabetic type
        if (isalpha(s[i]))
        {
            sum_l += 1;
        }
    }
    // printf("num of letters: %i\n", sum_l);
    return sum_l;
}

int count_words(string s)
{
    int sum_w = 0;

    for (int j = 0, n = strlen(s); j <= n; j++)
    {
        if (s[j] == ' ' || s[j] == '\0')
        {
            sum_w += 1;
        }
    }
    // printf("num of words: %i\n", sum_w);
    return sum_w;
}

int count_sentences(string s)
{
    int sum_s = 0;

    for (int k = 0, n = strlen(s); k < n; k++)
    {
        if (s[k] == '.' || s[k] == '!' || s[k] == '?')
        {
            sum_s += 1;
        }
    }
    // printf("num of sentences: %i\n", sum_s);
    return sum_s;
}

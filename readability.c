#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//List of all the functions and integers I need.
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int letters = 0;
int words = 1;
int sentences = 0;

int main(void)
{
    //We are getting the text to be evaluated
    string text = get_string("Please input text to be evaluated: \n");
    printf("Text: %s\n", text);
    printf("%i letter(s).\n", count_letters(text)); //made a function and inputed string text to count the LETTERS.  works.
    printf("%i word(sc).\n", count_words(text)); // made a function and inputed string text to count the WORDS. works
    printf("%i sentence(s).\n", count_sentences(text)); //made a function and inputed string text to count the SENTENCES. works.

    float l = (100.0 * (float) letters / words);
    float s = (100.0 * (float) sentences / words);

    printf("Value for l is %f\n", l);
    printf("Value for s is %f\n", s);

    float index = (0.0588 * l) - (0.296 * s) - 15.8;
    if (index >= 1 && index < 16)
    {
        printf("Grade %i\n", (int) round(index));
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
}

//Making a function to count the number of letters.
int count_letters(string text)
{
    for (int i = 0, n = strlen(text); i < n; i++) //loop to look at every letter in a string.
    {
    if (text[i] >= 'a' && text[i] <= 'z') //checking for lowercase letters and incrementing the integer letters.
    {
        letters++;
    }
    else if (text[i] >= 'A' && text[i] <= 'Z') //checking for uppercase letters and incrementing the integer letters.
    {
        letters++;
    }
    }
    return letters; //my function should return the integer letters.
}

//Making a function to count the number of words.
int count_words(string text)
{
    for (int i = 0, n = strlen(text); i < n; i++) //loop to look at every letter in a string.
    if (text[i] == ' ' && text[i + 1] != ' ')
    {
        words++;
    }
    return words;
}

int count_sentences(string text)
{
    for (int i = 0, n = strlen(text); i < n; i++) //loop to look at every letter in a string.
    if (text[i] == '.' || text[i] == '!' || text[i] == '?')
    {
        sentences++;
    }
    return sentences;
}
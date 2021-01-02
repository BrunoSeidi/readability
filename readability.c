#include <stdio.h>
#include <cs50.h>
#include <string.h> //i'll have to use strlen
#include <ctype.h>
#include <math.h>

//have to get total letter, words and sentences
//the formula is:      index = 0.0588 * L - 0.296 * S - 15.8

int main(void)
{
    string text = get_string("Text: "); //ask for the user
    int letters = 0;
    int words = 1; //one because we start counting at 0 in C
    int sentences = 0;

    int text_length = strlen(text);
    for (int i = 0; i < text_length; i++) //best loop when u know how many time will have to run
    {
        char character = text[i];
        if (isalpha(character))
        {
            letters++;
        }

        if (isspace(character))
        {
            words++;
        }

        if (character == '.' || character == '!' || character == '?')
        {
            sentences++;
        }
    }

    printf("%i letters\n", letters);
    printf("%i sentence(s)\n", sentences);
    printf("%i words\n", words);

    float le = (float) letters * 100 / words;
    float se = (float) sentences * 100 / words;
    int index = round(0.0588 * le - 0.296 * se - 15.8);

    if (index < 1)
    {
        printf("Before grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}



//the formula is:      index = 0.0588 * L - 0.296 * S - 15.8

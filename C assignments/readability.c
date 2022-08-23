//determines the reading level of the text provided by user. usage - ./readability

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    int words = count_words(text);
    int letters = count_letters(text);
    int sentences = count_sentences(text);
    float grade_actual = 5.88*letters/words - 29.6*sentences/words - 15.8;
    int grade = round(grade_actual);

    printf("%i\n", letters);
    printf("%i\n", words);
    
    if (grade_actual < 1)
    {
        printf("Before Grade 1\n");
    } else if (grade_actual > 16)
    {
        printf("Grade 16+\n");
    } else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string text)
{
    int count = 0;
    int text_length = strlen(text);
    for (int i = 0; i < text_length; i++)
    {
        if (isalpha(text[i]) || isdigit(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    int count = 1;
    int text_length = strlen(text);
    for (int i = 0; i < text_length; i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_sentences(string text)
{
    int count = 0;
    int text_length = strlen(text);
    for (int i = 0; i < text_length; i++)
    {
        if (text [i] == '.' || text [i] == '?' || text [i] == '!')
        {
            count++;
        }
    }
    return count;
}

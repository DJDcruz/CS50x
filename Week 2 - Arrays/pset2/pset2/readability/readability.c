#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int getIndex(string s);

int main(void)
{   
    //Receiving text from user input
    string text = get_string("Text: ");
    int index = getIndex(text);
    
    //Using the getIndex function to decide the reading grade of the text
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

//Function to compute the Coleman-Liau index of the text
int getIndex(string s)
{
    int sentences = 0, words = 0, letters = 0, spaces = 0, characters = 0;
    
    //Counting Letters
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == ' ')
        {
            spaces++;
        }
        characters++;
    }
    letters = characters - spaces;
    
    //CountingWords
    words = 1;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == ' ')
        {
            words++;
        }
    }
    
    //Counting Sentences
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            sentences++;
        }
    }
    
    //Using the Coleman-Liau index to compute the grade
    float L = ((float) letters / (float) words) * 100;
    float S = ((float) sentences / (float) words) * 100;
    
    int index = 0.0588 * L - 0.296 * S - 15.8;
    
    return round(index);
}
    

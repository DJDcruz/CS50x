#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int compute_score(string word);
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    //Get input from both players
    string p1 = get_string("Player 1: ");
    string p2 = get_string("Player 2: ");
    
    //Compute score for both players
    int s1 = compute_score(p1);
    int s2 = compute_score(p2);
    
    //Deciding who wins
    if (s1 > s2)
    {
        printf("Player 1 wins!\n");
    }
    else if (s2 > s1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("It's a tie!\n");
    }

}

int compute_score(string word)
{
    //Score counter
    int s = 0;
    
    //Computing score for each character in the word
    for (int i = 0, n = strlen(word); i < n; i++)
    { 
        if (isupper(word[i]))
        {   
            s += points[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            s += points[word[i] - 'a'];
        }
    }
    
    return s;
}
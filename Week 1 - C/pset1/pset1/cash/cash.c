#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Getting input from user
    float dollars;
    do
    {
        dollars = get_float("Money owed: ");
    }
    while (dollars < 0);
    
    //Rounding dollars to cents to get an integer
    int cents = round(dollars * 100);
    int coins = 0; 
   
    //Creating a greedy algorithm to use least no. of coins
    while (cents >= 25)
    {
        cents -= 25;
        coins++;
    }
   
    while (cents >= 10)
    {
        cents -= 10;
        coins++;
    }
   
    while (cents >= 5)
    {
        cents -= 5;
        coins++;
    }
   
    while (cents >= 1)
    {
        cents -= 1;
        coins ++;
    }
    
    //Printing no. of coins needed
    printf("Coins: %i\n", coins);
    
}
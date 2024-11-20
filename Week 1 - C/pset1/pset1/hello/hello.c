#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Get name of user & greet user
    string x = get_string("What is your name?\n");
    printf("Hello, %s\n", x);
}
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int num;
    
    // do while loop to act as a gate
    do {
        num = get_int("height: ");
    } while (num < 1 || num > 8);
    
    // if number is between 1 and 8, proceed to loops
    for (int i = 0; i < num; i++)
    { 
        for(int j = 0; j < num - i - 1; j++)
        {
            printf(" ");
        }
        for(int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
// finally got it to work :) 
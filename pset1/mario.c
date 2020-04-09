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

        // this loop just prints the spaces
        for(int j = 0; j < num - i - 1; j++)
        {
            printf(" ");
        }
        // this loop prints the #
        for(int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        // this printf is inbetween the loops to give a space between the pyramids
        printf("  ");

        // the next two loops are the same as the top just inverted.
        for(int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
/*
        for(int j = 0; j < num - i - 1; j++)
        {
            printf(" ");
        }
        */
        // then go to the next line and repeat
         printf("\n");
    }
}


#include <stdio.h>

int main(void)
{
    int num = 8;

    // make a pyramid of # height tall and height wide

    // print one # then 7 spaces
    // print two # and 6 space
    // ...

    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < num + i + 1; j++)
        {
            printf("#");
            for(int k = num - 1; k > 0; k--)
            {
                printf(".");
            }
        }
        printf("\n");
    }
}
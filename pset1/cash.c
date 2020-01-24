#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float amount;
    int coins = 0; //variable to keep track of each coin used
    
    // make sure the input is a float
     do {
        amount = get_float("Change owed: "); // get the amount of change
    } while (amount < 0);

    // convert the float input to an whole number integers
    // easier to work with
    int change = (int) round(amount * 100); 
    // get the amount of quarters
    

    // TODO - come back to this...seems inefficient
    while (change >= 25) { 
        change -= 25;
        coins++;
    }
    // get the amount of dimes
    while (change >= 10) { 
        change -= 10;
        coins++;
    } 
    // nickels...
    while (change >= 5) {
        change -= 5;
        coins++;
    } 
    // and pennies...
    while (change >= 1) { 
        change -= 1;
        coins++;
    }
    
    // print the amount of coins it took to creat the change
    printf("%i\n", coins); 
}
#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float change;
    
    float quarter = 0.25;
    float dime = 0.1;
    float nickel = 0.05;
    float penny = 0.01;
    
    int coins = 0; //variable to keep track of each coin used
    
    // make sure the input is a float
     do {
        change = get_float("Change owed: "); // get the amount of change
    } while (change < 0);
    
    while (change - quarter > 0) { // get the amount of quarters
        change = change - quarter;
        coins++;
    }
    
    while (change - dime > 0) { // get the amount of dimes
        change = change - dime;
        coins++;
    } 
    
    while (change - nickel > 0) { // nickels...
        change = change - nickel;
        coins++;
    } 
    
    while (change - penny > 0) { // and pennies...
        change = change - penny;
        coins++;
    } 
    
    printf("%d\n", coins); // print the amount of coins it took
}
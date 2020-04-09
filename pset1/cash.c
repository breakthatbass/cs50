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
    int quarters = change / 25;
    int dimes = (change % 25) / 10;
    int nickels = ((change % 25) % 10) / 5;
    int pennies = ((change % 25) % 10) % 5;

    int change_owed = quarters + dimes + nickels + pennies;

    printf("%i\n", change_owed);

}

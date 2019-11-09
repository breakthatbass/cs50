#include <cs50.h>
#include <stdio.h>
#include <string.h>

// main takes two argumaents: an int and a string
int main(int argc, string argv[])
{
    string s;
    // argv[] is an array of strings - even if those strings are numbers
    // atoi() converts those strings to integers
    int k = atoi(argv[1]) % 26; // store remainder if greater than 26

    // check to make sure there are only two arguments
    if (argc == 2 )
    {
        // prompt the user to input a string to be converted
        s = get_string("plaintext:");

        printf("ciphertext: ");
        
        //iterate through each char in string
        for(int i = 0; i < strlen(s); i++)
        {
            // convert each char to an int
            // add k to each char and print to terminal
           int c = (int) s[i] + k;
           
           printf("ciphertext: %c", c);
        }
        printf("\n");
        
        return 0;
    } else
    {
        // if you do it wrong 'usage' shows what to do
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
}


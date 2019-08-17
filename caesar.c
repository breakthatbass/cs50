#include <cs50.h>
#include <stdio.h>
#include <string.h>

// main takes two argumaents: an int and a string
int main(int argc, string argv[])
{
    string s;
    int k = atoi(argv[1]);
    // check to make sure there are only two arguments
    if (argc == 2 )
    {
        // prompt the user to input a string to be converted
        s = get_string("plaintext:");
        
        //iterate through each char in string
        for(int i = 0; i < strlen(s); i++)
        {
            // convert each char to an int
           int c = (int) s[i];
           // add k to each char and print to terminal
           printf("ciphertext: %c\n", c + k); // got a bug to fix here!!
        }
        return 0;
    } else
    {
        // unsure why "Usage: " is necessary here but it is what the directions asked for
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
}


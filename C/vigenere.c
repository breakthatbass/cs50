#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// main takes two argumaents: an int and a string
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //int key = atoi(argv[1]) % 26; // if argv[1] > 26, keep the remainder instead
   
    string keyword = argv[1];
    string plaintext = get_string("Plaintext: ");
    printf("Cipehertext: ");
    int plaintext_length = strlen(plaintext);
    
    // create an empty array that is the length of word input
    int key_arr[plaintext_length];
    // loop through each char of argv[i]
    for(int i = 0, j = 0; i < plaintext_length; i++)
    {
        // i use a second counter variable here to get reset and start from beginning
        // of word if it is shorter than the plainttext input
        
        if (keyword[i] != '\0')
        //if (j <= word_length)
        {
            
            int fix = isupper(plaintext[i]) ? 65 : 97;
            // push each value to the array
            key_arr[i] = keyword[j]; 
            
                if (plaintext[i] == 32) // 32 is ascii code for space
                {
                    key_arr[i] = 32; 
                }   
            j++;
        }
        else // if end of key array is reached, start over
        {
            j = 0;
        }
        
        printf("%c", key_arr[i]);
    }
    printf("\n");

    return 0;
}
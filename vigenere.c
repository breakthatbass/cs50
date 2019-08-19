#include <cs50.h>
#include <stdio.h>
#include <string.h>

// not working yet :(

int main(int argc, string argv[])
{
    char * plaintext;
    char * keyword = argv[1]; 
    int c;
    
    if (argc != 2){
        printf("Usage: ./vigenere keyword\n");
        return 1;
    } else
    {
        
     // prompt the user to input a string to be converted
        plaintext = get_string("plaintext:");

        printf("ciphertext: ");
        
        //iterate through each char in string
        for(int i = 0; i < strlen(plaintext); i++)
        {
            for(int j = 0; j < strlen(keyword); j++){
             c = (int) (plaintext[i] + keyword[i]) % 26; 
            }
            //loop through keyword
            //make keyword an int
           
           
           printf("ciphertext: %c", c);
        }
        printf("\n");
        
        return 0;
    }
}
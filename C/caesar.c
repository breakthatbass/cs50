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
    int key = atoi(argv[1]) % 26; // if argv[1] > 26, keep the remainder instead
    string word = get_string("Plaintext:");

    for(int i = 0; i < strlen(word); i++)
    {

        // all of this weird nonsense is required to loop back around to a if the letters go past z
        int fix = isupper(word[i]) ? 65 : 97;
        int pi = word[i] - fix;
        int ci = (pi + key) % 26;
        printf("%c", ci + fix);

    }
    printf("\n");
    return 0;
}


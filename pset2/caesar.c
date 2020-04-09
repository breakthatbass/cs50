#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <cs50.h>

// main takes two argumaents: an int and a string
int main(int argc, char *argv[])
{
    int key;
    string word;

    if (argc != 2) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    key = atoi(argv[1]) % 26; // if argv[1] > 26, keep the remainder instead
    word = get_string("plaintext: ");
    printf("ciphertext: ");

    for(int i = 0; i < strlen(word); i++) {
      // if element is not a character, print the element instead of changing it
        if (!isalpha(word[i])) {
          printf("%c", word[i]);
          continue;
        }

        int fix = isupper(word[i]) ? 65 : 97;
        int a = word[i] - fix;
        int b = (a + key) % 26;
        printf("%c", b + fix);
    }
    printf("\n");
    return 0;
}

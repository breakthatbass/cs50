# cs50 pset 6
from cs50 import get_string
import sys


def main():
    if len(sys.argv) != 2:
        print("Usage: ./caesar key") # Remind user to giv an argument

    # converts the word into int
    key = int(sys.argv[1])

    word = get_string("Plaintext: ")
    print("Cyphertext: ", end="")

    #loop through each char in str and add the k ints to it
    fix = 65 if word.isupper() else 97
    for i in range(len(word)):

        # convert strings to unicode numbers
        a = ord(word[i])
        b = ((((a - fix) + key) % 26) + fix)
        c = chr(b)
        print(c, end="")

    print()

if __name__ == "__main__":
    main()
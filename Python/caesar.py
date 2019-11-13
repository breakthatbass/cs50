# cs50 pset 6
from cs50 import get_string
from sys import argv
from string import *
import sys

# converts the word into ints
k = atoi(sys.argv[1]) % 26 # currently not working...will do later

# if there is only one extra command line arg, ...
if len(sys.argv) == 2:
    s = get_string("Plaintext:")
    print("Cyphertext:")

    #loop through each char in str and add the k ints to it
    for i in range(len(s)):

        c = s[i] + k
        print("ciphertext:", c)

else:
    print("Usage: ./caesar key");
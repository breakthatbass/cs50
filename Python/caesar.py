# cs50 pset 6
from cs50 import get_string
from sys import argv
from string import *
import sys

if len(sys.argv) != 2:
    print("Usage: ./caesar key")

# converts the word into ints
key = sys.argv[1] % 26 # currently not working...will do later
word = get_string("Plaintext:")
print("Cyphertext:")

    #loop through each char in str and add the k ints to it
for i in range(len(word)):
    c = word[i] + key
    print(c)
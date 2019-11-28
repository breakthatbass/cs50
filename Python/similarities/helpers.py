import sys
import os
from nltk.tokenize import sent_tokenize
# reusABLE variables for two command line args

a = sys.argv[2]
b = sys.argv[3]

def lines(a, b):
    a = sys.argv[2]
    b = sys.argv[3]
    """Return lines in both a and b"""


    if not os.path.isfile(a or b):
       print("usage: ./compare --line file1.ext file2.ext")
       sys.exit(1)

    # lists to seperate each line into elements
    lines1 = []
    lines2 = []
    # list to collect all the matching lines
    matches = []

    with open(a) as fp1:
       for line in fp1:
           # add each line from file to lines1 list
        lines1.append(line.rstrip())

    with open(b) as fp2:
       for line in fp2:
           # add each line from file to lines2 list
        lines2.append(line.rstrip())

    for el1 in lines1:
        for el2 in lines2:
            # compare each line
            if el1 == el2:
                # if lines match, append to matches list
                matches.append(el1)

    return matches


def sentences(a, b):
    """Return sentences in both a and b"""
    a = sys.argv[2]
    b = sys.argv[3]

    # list for matching sentences from files
    matches = []

    # open file of first command line arg
    fp1 = open(a).read()
    #seperate it into seperate sentences
    token1 = sent_tokenize(fp1)
    
    # open file of second command line arg
    fp2 = open(b).read()
    token2 = sent_tokenize(fp2)

    # iterate through both files
    for i in token1:
        for j in token2:
            # if sentences match, append to matches list
            if i == j:
                matches.append(i)

    if len(matches) == 0:
        print("there were no matches.")
    else:
        return matches



def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    # TODO
    return []

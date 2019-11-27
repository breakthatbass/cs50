import sys
import os
from nltk.tokenize import sent_tokenize

def lines(a, b):
    """Return lines in both a and b"""

    # variables for two command line args
    a = sys.argv[2]
    b = sys.argv[3]


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

    # TODO
    return []


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    # TODO
    return []

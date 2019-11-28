import sys
import os
from nltk.tokenize import sent_tokenize


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

    if not os.path.isfile(a or b):
       print("usage: ./compare --sentences file1.ext file2.ext")
       sys.exit(1)

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
    # arg shortcuts
    a = sys.argv[3]
    b = sys.argv[4]
    n = sys.argv[2] # n is length of substring

    # counting variables
    i = 0
    k = 0
    # convert to int because even though arg is a number, it args come as strings
    j = int(n)

    # empty lists to append to
    sub_str1 = []
    sub_str2 = []
    matches = []

    # list of things to remove from strings
    crap = [' ', '!', '?', '.', ',', '"']

    # short cuts for opening and reading files
    fp1 = open(a).read()
    fp2 = open(b).read()
    
    # loop through files and remove anything that is in crap list
    for el in crap:
        fp1 = fp1.replace(el, '')
    for el in crap:
        fp2 = fp2.replace(el, '')

    while i < len(fp1):
        # make sure splice end doesn't go past length of string
        if j > len(fp1):
            break
        else:
            # splice string starting at index 0 and ending at j which is the int
            sObject = slice(k, j)
            # append spliced section fo string
            sub_str1.append(fp1[sObject])
            k += 1
            j += 1
            i += 1

    # reset variables for next loop
    # only works as global vars and not within loops
    # I'm not sure why
    k = 0
    j = int(n)
    i = 0

    while i < len(fp2):
        if j > len(fp2):
            break
        else:
            sObject = slice(k, j)
            sub_str2.append(fp2[sObject])
            k += 1
            j += 1
            i += 1

    # iterate through both list and appened matching els to new list
    for el1 in sub_str1:
        for el2 in sub_str2:
            if el1 == el2:
                matches.append(el1)

    # remove any duplicates from matches list
    matches = list(dict.fromkeys(matches))

    return matches


import sys
import os

def lines(a, b):
    """Return lines in both a and b"""
    a = sys.argv[2]
    b = sys.argv[3]


    if not os.path.isfile(a or b):
       print("usage: ./compare --line file1.ext file2.ext")
       sys.exit(1)

    lines1 = []
    lines2 = []
### try this after as one
    with open(a) as fp1:
       for line in fp1:
           # add each line from file to lines1 list
        lines1.append(line)

    with open(b) as fp2:
       for line in fp2:
           # add each line from file to lines2 list
        lines2.append(line)

### TODO
# iterate through both lines lists and find elements that they both have in common
# append those to a new list
# return that list

    print("Lines1 list:")
    print(lines1)
    print()
    print("Lines2 list:")
    print(lines2)


    # TODO
    #return []


def sentences(a, b):
    """Return sentences in both a and b"""

    # TODO
    return []


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    # TODO
    return []

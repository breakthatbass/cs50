from cs50 import get_string
import sys
import os


def main():

    filepath = sys.argv[1]

    #if the filepath isn't in the directory, exit and explain usage
    if not os.path.isfile(filepath):
       print("usage: python filename.py file_to_read.ext")
       sys.exit(1)

    banned_words = [] #empty list to append elements from file
    with open(filepath) as fp:
       cnt = 0
       for line in fp:
           # add each line from file to banned_words list
           banned_words.append(line)
           cnt += 1
    # prompt user for a message/sentence
    msg = get_string("message: ")

    #split each word of msg into seperate elements
    split_msg = msg.split()

    # loop through both lists, compare each element
    for item in banned_words:
        for item1 in split_msg:
            # if elements match, ...
            if item.strip('\n') == item1:
                i = 0
                new_str = ""
                # get the index of that word in the message list
                index_of = split_msg.index(item1)

                # create a new string consisting of "*" matching the length of the word
                while i < len(item1):
                    new_str += "*"
                    i += 1
                # add the new_str in the place of the matched word
                split_msg.insert(index_of, new_str)
                # then remove matched word
                split_msg.remove(item1)
                # print out all the elements in the list but concatinate all elements with a space
                print(" ".join(split_msg))

if __name__ == "__main__":
    main()
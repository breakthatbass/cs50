from cs50 import get_int

def main():
    brick = get_height("Height:")

    for i in range(brick):

        # print spaces
        for j in range(brick - i - 1):
            print(" ", end="")

        # print hashes
        for k in range(i + 1):
            print("#", end="")

        # print space between each pyramid
        print("  ", end="")

        # print hashes
        for k in range(i + 1):
            print("#", end="")

        # print spaces
        for j in range(brick - i - 1):
            print(" ", end="")

        # go to the next line in the terminal
        print()

# Get a number from user
def get_height(prompt):
    while True:
        brick = get_int(prompt)

        # Make sure it is between 1 and 8
        if brick > 0 and brick < 9:
            break
    return brick

if __name__ == "__main__":
    main()
from cs50 import get_float

def main():

    # variable to keeps track of amount of coins
    coins = 0

    # get positive float from user
    i = get_pos_float("Change Owed: ")

    # change the float to a whole number
    change = i * 100

    # get the amount of quarters
    while change >= 25:
        change -= 25
        coins += 1

    # get the amount of dimes
    while change >= 10:
        change -= 10
        coins += 1

    # nickels...
    while change >= 5:
        change -= 5
        coins += 1

    # and pennies...
    while change >= 1:
        change -= 1
        coins += 1

    # print the amount of coins it took to creat the change
    print(coins)


 # function to keep asking for positive float from user as long as it's not positive
def get_pos_float(prompt):
    while True:
        num = get_float(prompt)
        if num > 0:
            break
    return num

if __name__ == "__main__":
    main()
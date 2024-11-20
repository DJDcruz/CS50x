from cs50 import get_int


# Getting the height input from user
h = get_int("Height: ")

# Using a do while loop to get a height within the parameters
while h < 1 or h > 8:
    h = get_int("Height: ")

#  a for loop to print the spaces and #s required
for i in range(h):
    for d in range(h - i - 1):
        print(" ", end="")
    
    for j in range(i + 1):
        print("#", end="")
    print()
        
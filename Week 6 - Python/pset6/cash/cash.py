from cs50 import get_float

# Get user input in dollars
dollars = get_float("Money owed: ")

# Dollars cannot be negative
while dollars < 0:
    dollars = get_float("Money owed: ")
    
# Converting dollars to cents    
cents = round(dollars * 100)
coins = 0

while cents >= 25:
    cents -= 25
    coins += 1

while cents >= 10:
    cents -= 10
    coins += 1
    
while cents >= 5:
    cents -= 5
    coins += 1

while cents >= 1:
    cents -= 1
    coins += 1
    
print("Coins: ", coins)
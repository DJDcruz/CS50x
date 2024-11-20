from cs50 import get_string


# Gets input
text = get_string("Text: ")

words = 1
sentences = letters = 0

# Iterates over string to find letters, words & sentences
for i in text:
    if i.isalpha():
        letters += 1

    if i.isspace():
        words += 1

    if i == '.' or i == '!' or i == '?':
        sentences += 1

L = letters / words * 100
S = sentences / words * 100

# Coleman-Liau's index
index = round(0.0588 * L - 0.296 * S - 15.8)

# Assigning the grades according to the index
if index >= 16:
    print("Grade 16+")

elif index < 1:
    print("Before Grade 1")

else:
    print(f"Grade {index}")
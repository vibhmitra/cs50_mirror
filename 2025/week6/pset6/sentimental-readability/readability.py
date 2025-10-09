# Coleman-Liau Index : Index = 0.0588 * L - 0.296 * S - 15.8
# L is the average number of letters per 100 word
# S is the average number of sentences per 100 words in the text.

# count the number of letters, words, and sentences in the text
# if A-Z, a-z -> letter
# if seperated by space -> word
# if seperated by . ! ?  -> sentence

# if grade index > 16 -> Grade 16+
# if grade index < 1 -> Before Grade 1

# TODO:
# 1. get user input
# 2. count letters
# 3. count words
# 4. count sentences
# 5. cal index using formula

import cs50

# vars
letters = 0
words = 1
sentences = 0

# input
text = cs50.get_string("Text: ")

# cals letters, words, sentences
for l in text:
    if l.isalpha():
        letters += 1
    elif l == " ":
        words += 1
    elif l == "!" or l == "?" or l == ".":
        sentences += 1

# the index
L = letters / words * 100
S = sentences / words * 100

index = round(0.0588 * L - 0.296 * S - 15.8)

# printing results
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")

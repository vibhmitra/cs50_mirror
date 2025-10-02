phrase = input("...")

if phrase == "hello":
    print(f"{phrase}, Human!")

# supports mulitple data types in List
my_list = ["Apple", 45, 2.3]
my_list.append(5)
# my_list = ["Apple", 45, 2.3, 5]
my_list.append(6)
my_list.insert(2, "Expresso")
my_list.pop(1)
my_list.reverse()
# my_list.sort()

text = "Wow, thats So great"
text.lower() # wow, thats so great
text.capitalize() # Wow, Thats So Great

# For Loops
for i in [0, 1, 2]:
    print(i, end="")
print()

# for i in range (start, end, step)
for i in range(0, 3, 1):
    print(i, end="")
print()

for i in range(3): # as step, and start defaults to 1, and 0
    print(i, end="")
print()

for i in range(len(text)):
    print(text[i], end="")
print()

for char in text:
     print(char, end="")
print()

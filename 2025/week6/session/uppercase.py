before = input("Before: ")
print("After: ", end="")
for c in before:
    print(c.upper(), end="")

print() # dont be confuse, this only added just to add a newline thats all

# or bro u can easily do it like this
after = before.upper()
print(f"After2: {after}")

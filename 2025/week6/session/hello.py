from cs50 import get_string

# answer = input("What's your name?") 👈 this is how native python input works
answer = get_string("What's your name? ")

# print("hello" + answer)
# print("hello, ", answer) <-- this also works
print(f"hello, {answer}", end="! 😊\n") # this is called variable interpolation {xxx} 👈 yep! the bracket thing

# variable deceration
# counter = 0   # <- it will find its type automatically
# counter += 1 # (valid)
# counter = counter + 1 # (valid)
# counter++ or ++counter # (invalid ⚠️)

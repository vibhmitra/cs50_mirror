# i = 0
# while i < 3:
#     print("Meow 😺")
#     i += 1

# for _ in ["cat1", "cat2", "cat3"]:
#     print("Meow 🙀")


# for _ in range(3):
#     print("Meow 😺")

def main():     # def 1
    meow(3)

def meow(n):     # def 2
    for _ in range(n):
        print("meow 🙀")

# if __name__ == "__main__":  👈 this is useful when u make library of you own.

main()  # yo we called it here

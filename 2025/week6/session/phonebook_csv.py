import csv

# one way to do it
# file = open("phonebook.csv", "a")

# name = input("Name: ")
# number = input("Number: ")

# write = csv.writer(file)
# write.writerow([name, number])

# file.close()

### or wecan do this like this

name = input("Name: ")
number = input("Number: ")

with open("phonebook.csv", "a") as file:
    writer = csv.DictWriter(file, fieldnames=["name", "number"])
    writer.writerow({"name": name, "number": number})


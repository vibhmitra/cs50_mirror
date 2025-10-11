import csv, os

name = input("Name: ")
number = input("Number: ")

file_exists = os.path.exists("phonebook.csv")

with open("phonebook.csv", "a") as file:
    writer = csv.DictWriter(file, fieldnames=["name", "number"])

    if not file_exists:
        writer.writeheader()

    writer.writerow({"name": name, "number": number})

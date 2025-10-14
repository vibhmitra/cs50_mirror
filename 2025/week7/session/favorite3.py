import csv

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)   # Dict reader helps us iterate using the actual key like lets say if structure of column moved or smth like that
    # next(reader) #  👈 skips header
    for row in reader:
        print(row["language"])

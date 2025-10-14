import csv

with open("favorites.csv", "r") as file:
    reader = csv.reader(file)
    next(reader) #  👈 skips header
    for row in reader:
        favorite = row[1]
        print(favorite)

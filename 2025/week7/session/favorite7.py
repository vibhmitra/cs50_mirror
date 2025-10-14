import csv
from collections import Counter

with open("favorites.csv") as file:
    reader = csv.DictReader(file)
    counts = Counter()

    for row in reader:
        favorite = row["problem"]
        counts[favorite] += 1

favorite = input("Favorites: ")
print(f"{favorite} : {counts[favorite]}")

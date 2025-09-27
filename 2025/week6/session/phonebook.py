names = ["Yulia", "David", "Joo"]

name = input("name: ")

# for n in names:
#     if name == n:
#         print("Found")
#         break
# else:
#     print("Not found")

if name in names:
    print("Found")
else:
    print("Not found")

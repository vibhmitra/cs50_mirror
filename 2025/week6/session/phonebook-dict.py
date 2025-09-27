# people = [
#     {"name":"Yulia", "number":"+4535634"},
#     {"name":"David", "number":"+6453525"},
#     {"name":"John", "number":"+34632542"},
# ]

# input_name = input("Name: ")

# for person in people:
#     if person["name"] == input_name:
#         number = person["number"]
#         print(f"Found {number}")
#         break
# else:
#     print("Not Found")

people = {
    "yulia": "+87584798",
    "david": "+85794",
    "john": "+98457",
}

input_name = input("Name: ").lower()
print(f"Search string: {input_name}")


if input_name in people:
    print(f"Found\n Number: {people[input_name]}")
else:
    print("Not Found")

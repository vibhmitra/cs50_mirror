import cs50

while True:
    n = cs50.get_int("Height: ")  # new way to access fucntion because python uses like a namespace thing
    if n > 0:
        break

for i in range(n):
    print("#")

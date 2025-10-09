import cs50

# mario


def mario(h):
    for build in range(h):
        print(" " * (h - build - 1) + "#" * (build + 1))
    return 0


# getting height
invalid = True
while invalid:
    height = cs50.get_int("Height: ")
    if height not in range(1, 9):
        print("Invalid height. Must be a positive number.")
        invalid = True
    else:
        invalid = False
        mario(height)

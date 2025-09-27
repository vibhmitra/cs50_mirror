

s = input("Do you agree? ").lower()  # <-- thus 

if s == "Y" or s == "y":
    print("Agreed.")
elif s == "N" or s == "n":
    print("Do not Agreed.")

# a silghtly better way using csv!
if s in ["Y", "y"]:
     print("yep.")
elif s in ["N", "n"]:
    print("nope.")

# a more better way tho
t = s.lower()

if t in ["y", "yes"]:
     print("yooo.")
elif t in ["n", "no"]:
    print("nooo.")

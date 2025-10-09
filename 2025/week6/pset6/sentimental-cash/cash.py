import cs50


#     // Prompt the user for change owed, in cents
while True:
    change = cs50.get_float("change: ")
    if change > 0:
        break

change = round(change * 100)
coins = 0
#     // Calculate how many quarters you should give customer
#     // Subtract the value of those quarters from cents
while change >= 25:
    change -= 25
    coins += 1

#     // Calculate how many dimes you should give customer
#     // Subtract the value of those dimes from remaining cents
while change >= 10:
    change -= 10
    coins += 1

#     // Calculate how many nickels you should give customer
#     // Subtract the value of those nickels from remaining cents
while change >= 5:
    change -= 5
    coins += 1

#     // Calculate how many pennies you should give customer
#     // Subtract the value of those pennies from remaining cents
while change >= 1:
    change -= 1
    coins += 1

#     // Print that sum
print(coins)

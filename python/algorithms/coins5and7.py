# the function change(amount) should returns a list consisting of only 5 and 7,
# such that their sum is equal to amount (24 <= amount <= 1000)

def change(amount):
    if amount == 20:
        return [5, 5, 5, 5]
    if amount == 22:
        return [5, 5, 5, 7]
    if amount == 24:
        return [5, 5, 7, 7]
    if amount == 26:
        return [5, 7, 7, 7]
    if amount == 28:
        return [7, 7, 7, 7]

    coins = change(amount - 5)
    coins.append(5)
    return coins


money = change(788)
print(money)

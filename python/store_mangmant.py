"""
hello my name ahmed
this app is store mangmant 
version [1] you can: add, show, edit, delete, save, load
version [2] ues Exceptions and no error and use pylint and have rate 10 
"""
import os
names = []

prices = []

quantities = []


os.chdir(os.path.dirname(os.path.abspath(__file__)))

files = ["data_name.txt", "data_prices.txt", "data_quantities.txt"]

for file_name in files:
    try:

        with open(file_name, "x", encoding="utf-8"):

            pass

    except FileExistsError:

        pass


def add(namel: list, pricel: list, quantityl: list):
    """this function to add prodcuts to list"""

    name = input("write  new name: ").strip()

    price = input("write  new price: ").strip()

    try:

        price = int(price)

    except ValueError:

        print("ERROR:Please Enter Number\n")

        return

    quantity = input("write  new quantity: ").strip()

    try:

        quantity = int(quantity)

    except ValueError:

        print("ERROR:Please Enter Number\n")

        return

    namel.append(name)

    pricel.append(price)

    quantityl.append(quantity)


def show(namel: list, pricel: list, quantityl: list):
    """this function to show all prodcuts"""
    i = 0

    for name, price, quantity in zip(namel, pricel, quantityl):

        print(f"\
prodcut [{i}]\n\
=> name: {name}\n\
=> price: {price}\n\
=> quantities: {quantity}\n")

        i += 1


def delete(namel: list, pricel: list, quantityl: list):
    """"this function to delete one product"""
    show(namel, pricel, quantityl)

    index = input("choice the number of product: ")

    try:

        index = int(index)

        if index < 0:

            raise IndexError("LessZero")

        if index >= len(namel):

            raise IndexError()

    except ValueError:

        print("ERROR:Please Enter Number\n")

        return

    except IndexError:

        print("ERROR:Wrong number of product\n")

        return

    namel.pop(index)

    pricel.pop(index)

    quantityl.pop(index)


def edit(namel: list, pricel: list, quantityl: list):
    """this function to edit ane product"""
    show(namel, pricel, quantityl)

    index = input("choice the number of product: ")

    try:

        index = int(index)

        if index < 0:

            raise IndexError("LessZero")

        if index >= len(namel):

            raise IndexError()

    except ValueError:

        print("ERROR:Please Enter Number\n")

        return

    except IndexError:

        print("ERROR:Wrong number of product\n")

        return

    name = input("write  new name: ").strip()

    price = input("write  new price: ").strip()

    try:

        price = int(price)

    except ValueError:

        print("ERROR:Please Enter Number\n")

        return

    quantity = input("write  new quantity: ").strip()

    try:

        quantity = int(quantity)

    except ValueError:

        print("ERROR:Please Enter Number\n")

        return

    namel[index] = name

    pricel[index] = price

    quantityl[index] = quantity


def load(name: list, price: list, quantity: list):
    """this function to load data form files text"""

    with open(files[0], "r", encoding="utf-8") as file:

        name.extend(file.read().split('\n'))

    with open(files[1], "r", encoding="utf-8") as file:

        price.extend(file.read().split('\n'))

    with open(files[2], "r", encoding="utf-8") as file:

        quantity.extend(file.read().split('\n'))

    name.pop()

    price.pop()

    quantity.pop()


def save(namel: list, pricel: list, quantityl: list):
    """this fuction to save data products"""
    with open(files[0], "w", encoding="utf-8") as file:

        for name in namel:

            file.write(name + '\n')

    with open(files[1], "w", encoding="utf-8") as file:

        for price in pricel:

            file.write(f"{price}\n")

    with open(files[2], "w", encoding="utf-8") as file:

        for quantity in quantityl:

            file.write(f"{quantity}\n")


load(names, prices, quantities)


while True:

    print("\
[1] add\n\
[2] show\n\
[3] delete\n\
[4] edit\n\
[5] exit\n")

    choice = input("slecet your choice: ")
    print()
    try:

        choice = int(choice)

    except ValueError:

        print("ERROR:Please Enter Number\n")

    if choice == 1:

        add(names, prices, quantities)

    elif choice == 2:

        if len(names) > 0:

            show(names, prices, quantities)

        else:

            print("add prodcuts first\n")

    elif choice == 3:

        if len(names) > 0:

            delete(names, prices, quantities)

        else:

            print("add prodcuts first\n")

    elif choice == 4:

        if len(names) > 0:

            edit(names, prices, quantities)

        else:

            print("add prodcuts first\n")

    elif choice == 5:

        break

    elif choice != 5:

        print("wrong choice\n")


save(names, prices, quantities)

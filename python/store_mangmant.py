"""
hello my name ahmed
this app is store mangmant 
version [1] you can: add, show, edit, delete, save, load
version [2] ues Exceptions and no error and use pylint and have rate 10 
version [3] ues ues OOP
"""
import os


os.chdir(os.path.dirname(os.path.abspath(__file__)))

files = ["data_name.txt", "data_prices.txt", "data_quantities.txt"]

for file_name in files:
    try:

        with open(file_name, "x", encoding="utf-8"):

            pass

    except FileExistsError:

        pass

class Product:

    product_list = []

    def __init__(self):

        self.name = input("name: ")

        self.price = input("price: ")

        self.quantity = input("quantity: ")

        Product.product_list.append(self)




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

        pass

    elif choice == 2:

        pass

    elif choice == 3:

        pass

    elif choice == 4:

        pass

    elif choice == 5:

        break

    elif choice != 5:

        print("wrong choice\n")

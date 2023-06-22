names=[]
prices=[]
aqwnaty=[]
import os

os.chdir(os.path.dirname(os.path.abspath(__file__)))

files= ["data_name.txt","data_prices.txt","data_quantities.txt"]
if_file_exist = all(os.path.exists(f) for f in files)

if  if_file_exist:
    pass
else:
    file = open("data_name.txt",'x')
    file = open("data_prices.txt",'x')
    file = open("data_quantities.txt",'x')



def add(name:list,price:list,aqwnats:list):
    index = int(input("write how mny prodcut: ").strip())
    for i in range(0,index):
        name.append(input("name of prodcut: ").strip())
        price.append(int(input("price of prodcut: ").strip()))
        aqwnats.append(int(input("aqwnaty of prodcut: ").strip()))



def show(name:list,price:list,aqwnats:list):
    i=0
    for n,p,q in zip(name,price,aqwnats):
      print(f"\
prodcut [{i}]\n\
=> name: {n}\n\
=> price: {p}\n\
=> aqwnaty: {q}\n")
      i += 1



def delete(name:list,price:list,aqwnats:list):
    show(name,price,aqwnats)
    index= int(input("chose the number of product: "))
    name.pop(index)
    price.pop(index)
    aqwnats.pop(index)



def edit(name:list,price:list,aqwnats:list):
    show(name,price,aqwnats)
    index= int(input("chose the number of product: "))
    name[index] = input("write  new name: ").strip()
    price[index] = int(input("write  new price: ").strip())
    aqwnats[index] = int(input("write  new aqwnats: ").strip())


def load(name:list,price:list,aqwnats:list):
    file = open("data_name.txt","r")
    
    name.extend(file.read().split('\n'))
    
    file = open("data_prices.txt","r")
    
    price.extend(file.read().split('\n'))
    
    file = open("data_quantities.txt","r")
    
    aqwnats.extend(file.read().split('\n'))
    
    file.close()
    name.pop()
    price.pop()
    aqwnats.pop()



def save(name:list,price:list,aqwnats:list):
    file = open("data_name.txt","w")
    for n in name:
      file.write(n+'\n')
    
    
    file = open("data_prices.txt","w")
    for p in price:
      file.write(f"{p}\n")
    
    file = open("data_quantities.txt","w")
    for q in aqwnats:
      file.write(f"{q}\n")
    file.close()


load(names,prices,aqwnaty)

print("\
[1] add\n\
[2] show\n\
[3] delete\n\
[4] edit\n\
[5] exit\n")

choic = int(input("slecet your choic: "))
print()
while choic != 5:

  if choic == 1:
    add(names,prices,aqwnaty)

  elif choic == 2:
    show(names,prices,aqwnaty)
  elif choic == 3:
    delete(names,prices,aqwnaty)
  elif choic == 4:
    edit(names,prices,aqwnaty)
  else:
    print("wrong chose")

  print("\
[1] add\n\
[2] show\n\
[3] delete\n\
[4] edit\n\
[5] exit\n")
  choic = int(input("slecet your choic: "))
  print()
save(names,prices,aqwnaty)

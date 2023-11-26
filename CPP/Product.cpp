#include "main.h"

Product::Product()
{
    name = "";
    price = 0;
    quantity = 0;
};
Product::Product(string name_, double price_, int quantity_) : name(name_), price(price_),
                                                               quantity(quantity_)
{
}

Product::~Product() {}
void Product::print()
{
    cout << "name: " << name << endl;
    cout << "price: " << price << endl;
    cout << "quantity: " << quantity << endl;
}

void Product::edit_elment(string name_new, double price_new, int quantity_new)
{
    name = name_new;
    price = price_new;
    quantity = quantity_new;
}

void Product::save(ofstream &file)
{
    file << name << endl
         << price << endl
         << quantity << endl;
}
void Product::load(ifstream &file)
{
    file >> name >> price >> quantity;
}

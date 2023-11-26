#ifndef MAIN_H
#define MAIN_H
// Libraries
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

// class
class Product
{
    string name;
    double price;
    int quantity;

public:
    Product();
    Product(string name_, double price_, int quantity_);

    ~Product();
    void print();

    void edit_elment(string name_new, double price_new, int quantity_new);

    void save(ofstream &file);
    void load(ifstream &file);
};

// Global variable
extern vector<Product *> list_of_Product;

// functions
template <class type>
void input_num(type &x, string msg);
void set_data(string &, double &, int &);
void add();
void print_all();
void _delete();
void edit();
void save();
void load();

#endif
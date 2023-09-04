#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <limits>
using namespace std;
// function
template <class type>
void input_num(type &x, string msg);
void get_data(string &, double &, int &);
void add();
void print_all();
void _delete();
void edit();
void save();
void load();

class Product
{
    string name;
    double price;
    int q;

public:
    Product(){};
    Product(string name_, double price_, int q_) : name(name_), price(price_), q(q_)
    {
    }

    ~Product() {}
    void print()
    {
        cout << "name: " << name << endl;
        cout << "price: " << price << endl;
        cout << "q: " << q << endl;
    }

    void edit_elment(string name_new, double price_new, int q_new)
    {
        name = name_new;
        price = price_new;
        q = q_new;
    }
    
    void save(ofstream &file)
    {
        file << name << endl
             << price << endl
             << q << endl;
    }
    void load(ifstream &file)
    {
        file >> name >> price >> q;
    }
};
vector<Product *> list_of_Product;

int main()
{
    load();
    int choice = 0;
    while (choice != 5)
    {
        cout << "[1] add\n[2] show\n[3] delete\n[4] edit\n[5] exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            add();
            break;
        case 2:
            print_all();
            break;
        case 3:
            _delete();
            break;
        case 4:
            edit();
            break;

        default:
            cout << (choice != 5 ? "wrong choice" : "");
            break;
        }
    }
    save();
    return 0;
}
void get_data(string &name, double &price, int &q)
{
    cin.ignore();
    cout << "name: ";
    getline(cin, name);

    input_num(price, "enter price: ");

    input_num(q, "enter q: ");
}
void add()
{
    string name;
    double price;
    int q;

    get_data(name, price, q);

    Product *tmp = new Product(name, price, q);

    list_of_Product.push_back(tmp);
}
void print_all()
{
    if (list_of_Product.size() < 1)
    {
        cout << "add Product first\n";
        return;
    }
    for (int index = 0; index < list_of_Product.size(); index++)
    {
        cout << "[" << index << "]\n";
        list_of_Product[index]->print();
    }
}
void _delete()
{
    if (list_of_Product.size() < 1)
    {
        cout << "add Product first\n";
        return;
    }
    print_all();

    int index;

    input_num(index, "choice number of product: ");

    delete list_of_Product[index];
    list_of_Product.erase(list_of_Product.begin() + index);
}
void edit()
{
    if (list_of_Product.size() < 1)
    {
        cout << "add Product first\n";
        return;
    }

    print_all();

    int index;

    input_num(index, "choice number of product: ");

    string name;
    double price;
    int q;

    get_data(name, price, q);

    list_of_Product[index]->edit_elment(name, price, q);
}
template <class type>
void input_num(type &x, string msg)
{
    cout << msg;

    while (!(cin >> x))
    {
        cerr << "wrong value | number only\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << msg;
    }
}

void save()
{
    ofstream file;
    file.open("data.txt");
    for (auto prodect : list_of_Product)
    {
        prodect->save(file);
    }
    file.close();
}
void load()
{
    ifstream file;
    file.open("data.txt");
    if (!file)
    {
        return;
    }
    while (!(file.eof()))
    {
        Product *tmp = new Product();
        tmp->load(file);
        list_of_Product.push_back(tmp);
    }
}
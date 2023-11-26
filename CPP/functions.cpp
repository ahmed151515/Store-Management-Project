#include "main.h"

/**
 * set_data - from user
 * @name: name of product
 * @price: price of product
 * @quantity: quantity of product
 */
void set_data(string &name, double &price, int &quantity)
{
    cin.ignore();
    cout << "name: ";
    getline(cin, name);

    input_num(price, "enter price: ");

    input_num(quantity, "enter quantity: ");
}
/**
 * add - add one product to list
 */
void add()
{
    string name;
    double price;
    int quantity;

    set_data(name, price, quantity);

    Product *tmp = new Product(name, price, quantity);

    list_of_Product.push_back(tmp);
}
/**
 * print_all - print product from list
 */
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
/**
 * _delete - delete product from list
 */
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
/**
 * edit - edit product from list
 */
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
    int quantity;

    set_data(name, price, quantity);

    list_of_Product[index]->edit_elment(name, price, quantity);
}
/**
 * input_num -  input number from user
 * @var: variable
 * @msg: text to user
 * I use call by refraence
 */
template <class type>
void input_num(type &var, string msg)
{
    cout << msg;

    while (!(cin >> var))
    {
        cerr << "wrong value | number only\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << msg;
    }
}
/**
 * save - save product from list in text file
 */
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
/**
 * load - load product from text file to text file
 */
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
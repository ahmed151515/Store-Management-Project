#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
void save(vector<string> &names, vector<double> &prices, vector<int> &quantities)
{
    ofstream data;
    data.open("data_name.txt");
    for (int i = 0; i < names.size(); i++)
    {
        data << names.at(i) << "\n";
    }
    data.close();
    data.open("data_prices.txt");
    for (int i = 0; i < prices.size(); i++)
    {
        data << prices.at(i) << "\n";
    }
    data.close();
    data.open("data_quantities.txt");
    for (int i = 0; i < quantities.size(); i++)
    {
        data << quantities.at(i) << "\n";
    }
    data.close();
}
void load(vector<string> &names, vector<double> &prices, vector<int> &quantities)
{
    string name_l;
    double price_l;
    int quantities_l;
    ifstream data;

    data.open("data_name.txt");
    if (data.is_open())
    {
        while (data >> name_l)
        {
            names.push_back(name_l);
        }
    }
    data.close();
    data.open("data_prices.txt");
    if (data.is_open())
    {
        while (data >> price_l)
        {
            prices.push_back(price_l);
        }
    }
    data.close();
    data.open("data_quantities.txt");
    if (data.is_open())
    {
        while (data >> quantities_l)
        {
            quantities.push_back(quantities_l);
        }
    }
    data.close();
}
void add(vector<string> &names, vector<double> &prices, vector<int> &quantities)
{
    int count = 0, quantity;
    string name;
    double price;
    cout << "How mnay products you want add\n";
    cin >> count;
    cin.ignore();
    for (int i = 0; i < count; i++)
    {
        cout << "write name of product\n";
        getline(cin, name);
        names.push_back(name);
        cout << "write price of product\n";
        cin >> price;
        prices.push_back(price);
        cout << "write quantity of product\n";
        cin >> quantity;
        cin.ignore();
        quantities.push_back(quantity);
    }
}
void show(vector<string> names, vector<double> prices, vector<int> quantities)
{
    for (int i = 0; i < names.size(); i++)
    {
        cout << "product [" << i << "]\nname: " << names.at(i)
             << "\nprice: " << prices.at(i) << "\nquantity: " << quantities.at(i) << "\n\n";
    }
}
void Delete(vector<string> &names, vector<double> &prices, vector<int> &quantities)
{
    show(names, prices, quantities);
    int index;
    cout << "what the index you want delete\n";
    cin >> index;
    if (index >= names.size())
        cout << "Wrong index\n";
    else
    {
        for (int i = index; i <= index; i++)
        {
            names.erase(names.begin() + i, names.begin() + i + 1);
            prices.erase(prices.begin() + i, prices.begin() + i + 1);
            quantities.erase(quantities.begin() + i, quantities.begin() + i + 1);
        }
        cout << "Deleted successfully\n";
    }
}
void edit(vector<string> &names, vector<double> &prices, vector<int> &quantities)
{
    show(names, prices, quantities);
    int index, quantity;
    string name;
    double price;
    cout << "what the index you want edit\n";
    cin >> index;
    cin.ignore();
    if (index >= names.size())
        cout << "Wrong index\n";
    else
    {
        for (int i = 0; i < 1; i++)
        {
            cout << "write new name of product\n";
            getline(cin, name);
            names.at(index) = name;
            cout << "write new price of product\n";
            cin >> price;
            prices.at(index) = price;
            cout << "write new quantity of product\n";
            cin >> quantity;
            quantities.at(index) = quantity;
            cin.ignore();
        }
        cout << "Edited successfully\n";
    }
}
int main()
{
    vector<string> name;
    vector<double> price;
    vector<int> quantity;
    load(name, price, quantity);
    int choice = 0;
    while (choice != 5)
    {
        cout << "Select Choose\n";
        cout << "[1] add\n";
        cout << "[2] show\n";
        cout << "[3] delete\n";
        cout << "[4] edit\n";
        cout << "[5] exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            add(name, price, quantity);
            break;
        case 2:
            if (name.empty() && price.empty() && quantity.empty())
                cout << "Please add products first\n";
            else
                show(name, price, quantity);
            break;
        case 3:
            if (name.empty() && price.empty() && quantity.empty())
                cout << "Please add products first\n";
            else
            {
                Delete(name, price, quantity);
            }

            break;
        case 4:
            if (name.empty() && price.empty() && quantity.empty())
                cout << "Please add products first\n";
            else
            {
                edit(name, price, quantity);
            }

            break;
        case 5:
            break;
        default:
            cout << "Wrong choice\n";
        }
    }
    save(name, price, quantity);

    return 0;
}

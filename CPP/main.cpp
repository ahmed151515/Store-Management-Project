#include "main.h"

vector<Product *> list_of_Product;

int main()
{
    load();
    int choice;
    do
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
    } while (choice != 5);
    save();
    return 0;
}

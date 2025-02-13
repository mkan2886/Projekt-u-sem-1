#include "Interface.h"

void Interface::displayMenu() {
    cout << "1. Load products from file" << endl;
    cout << "2. Display inventory" << endl;
    cout << "3. Check stock levels" << endl;
    cout << "4. Check customer orders" << endl;
    cout << "5. Add new product" << endl;
    cout << "6. Add new BOM" << endl;
    cout << "7. Remove product" << endl;
    cout << "8. Update product quantity" << endl;
    cout << "9. Save to file" << endl;
    cout << "10. Exit" << endl;
    cout << "Choose option: " << endl; 
}

void Interface::run() {

    string filename;
    int id, quantity;
    string name, unit;
    double price;
    string material;
    double cost;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter a file name : ";
            cin >> filename;
            fu.loadFromFile(filename, iu.getItems());
            break;
        case 2:
            iu.displayInventory();
            break;
        case 3:
            iu.checkStockLevels();
            break;
        case 4:
            iu.checkOrders();
            break;
        case 5:
            cout << "Provide product details(id, name, quantity, unit, price): ";
            cin >> id >> name >> quantity >> unit >> price;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');;
                cout << "Wrong format, please try again" << endl;
                break;
            }
            else
            iu.addItem(new Product(id, name, quantity, unit, price));
            break;
        case 6:
            cout << "Provide product details (id, name, quantity, unit, material, cost): ";
            cin >> id >> name >> quantity >> unit >> material >> cost;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');;
                cout << "Wrong format, please try again" << endl;
                break;
            }else
            iu.addItem(new BOM(id, name, quantity, unit, material, cost));
            break;
        case 7:
            cout << "Enter the product id to remove: ";
            cin >> id;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');;
                cout << "Wrong format, please try again" << endl;
                break;
            }
            else
            iu.removeItem(id);
            break;
        case 8:
            cout << "Enter the product id and new quantity: ";
            cin >> id >> quantity;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');;
                cout << "Wrong format, please try again" << endl;
                break;
            }
            else
            iu.updateQuantity(id, quantity);
            break;
        case 9:
            cout << "Enter file name to save: ";
            cin >> filename;
            fu.saveToFile(filename, iu.getItems());
            break;
        case 10:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Wrong choice! Try again" << endl;
        }

    } while (choice != 10);

}
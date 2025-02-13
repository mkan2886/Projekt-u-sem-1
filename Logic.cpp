#include "Logic.h"

//ITEM UTILSE

ItemUtilise::ItemUtilise() {}

ItemUtilise::~ItemUtilise() {
    for (auto item : items) {
        delete item;
    }
}

void ItemUtilise::addItem(Item* item) {
    items.push_back(item);
}

void ItemUtilise::removeItem(int id) {
    auto it = items.begin();
    while (it != items.end()) {
        if ((*it)->getId() == id) {
            delete* it;
            it = items.erase(it);
        }
        else {
            ++it;
        }
    }
}

void ItemUtilise::updateQuantity(int id, int quantity) {
    for (auto& item : items) {
        if (item->getId() == id) {
            item->setQuantity(quantity);
            break;
        }
    }
}

void ItemUtilise::displayInventory() {
    for (const auto& item : items) {
        if (auto product = dynamic_cast<Product*>(item)) {
            product->display();
            for (const auto& bomItem : items) {
                if (auto bom = dynamic_cast<BOM*>(bomItem)) {
                    if (bom->getId() == product->getId()) {
                        cout << "BOM: "; 
                        bom->display();
                    }
                }
            }
        }
    }
}

void ItemUtilise::checkStockLevels() {
    for (const auto& item : items) {
        if (auto product = dynamic_cast<Product*>(item)) {
            if (product->getQuantity() < 10) {
                cout << "Product: " << product->getName() << " needs to be reordered." << endl;
            }
        }
    }
}

void ItemUtilise::checkOrders() {
    cout << "Enter product IDs and quantities (format: id quantity). Type 'done' when finished." << endl;
    while (true) {
        string input;
        cin >> input;
        if (input == "done") {
            break;
        }
        int id = stoi(input);
        int quantity;
        cin >> quantity;

        bool found = false;
        for (auto& item : items) {
            if (item->getId() == id) {
                item->setQuantity(item->getQuantity() + quantity);
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Product with ID " << id << " not found in inventory." << endl;
        }
    }
}

vector<Item*>& ItemUtilise::getItems() {
    return items;
}

//FILE UTILISE

FileUtilise::FileUtilise() {}
FileUtilise::~FileUtilise() {}

void FileUtilise::loadFromFile(const string& filename, vector<Item*>& items) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Nie mo¿na otworzyæ pliku: " << filename << endl;
        return;
    }

    string type, name, unit, material;
    int id, quantity;
    double price, cost;
    while (file >> type >> id >> name >> quantity >> unit) {
        if (type == "Product") {
            file >> price;
            items.push_back(new Product(id, name, quantity, unit, price));
        }
        else if (type == "BOM") {
            file >> material >> cost;
            items.push_back(new BOM(id, name, quantity, unit, material, cost));
        }
    }
    file.close();
}

void FileUtilise::saveToFile(const string& filename, const vector<Item*>& items) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Nie mo¿na otworzyæ pliku do zapisu: " << filename << endl;
        return;
    }

    for (const auto& item : items) {
        if (auto product = dynamic_cast<Product*>(item)) {
            file << "Product  " << product->getId() << " " << product->getName() << " "
                << product->getQuantity() << " " << product->getUnit() << " "
                << product->getPrice() << endl;
        }
        else if (auto bom = dynamic_cast<BOM*>(item)) {
            file << "BOM  "<< bom->getId() << " " << bom->getName() << " "
                << bom->getQuantity() << " " << bom->getUnit() << " "
                << bom->getMaterial() << " " << bom->getCost() << endl;
        }
    }
    file.close();
}
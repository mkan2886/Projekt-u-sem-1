#pragma once
#define LOGIC_H

#include "Data.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class ItemUtilise {
private:
    vector<Item*> items;
public:
  
    ItemUtilise();
    ~ItemUtilise();

    void addItem(Item* item);
    void removeItem(int id);
    void updateQuantity(int id, int quantity);
    void displayInventory();
    void checkStockLevels();
    void checkOrders();
 
    vector<Item*>& getItems();

};


class FileUtilise
{
public:

    FileUtilise();
    ~FileUtilise();

    void loadFromFile(const string& filename, vector<Item*>& items);
    void saveToFile(const string& filename, const vector<Item*>& items);
};


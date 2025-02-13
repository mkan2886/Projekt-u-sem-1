#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


class Item {

private:

    int id;
    string name;
    int quantity;
    string unit;

public:

 
    Item();
    Item(int id_, const string& n, int q, const string& u);
    ~Item();


    int getId();
    void setId(int a);
    
    string getName();
    void setName(const string& a);

    int getQuantity();
    void setQuantity(int a);

    string getUnit();
    void setUnit(const string& a);

    virtual void display() = 0;
};


class Product : public Item {

private:
  
    double price;
public:

    Product();
    Product(int id__, const string& n_, int q_, const string& u_, double p);
    ~Product();

    double getPrice();
    void setPrice(double a);

    void display() override;
};


class BOM : public Item {

private:

    string material;
    double cost;

public:


    BOM();
    BOM(int id___, const string& n__, int q__, const string& u__, const string& m, double c);
    ~BOM();


    string getMaterial();
    void setMaterial(const string& a);

    double getCost();
    void setCost(double a);

    void display() override;
};

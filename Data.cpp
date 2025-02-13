#include "Data.h"

Item::Item() : id(0), name("n"), quantity(0), unit("u") {};
Item::Item(int id_, const string& n, int q, const string& u) : id(id_), name(n), quantity(q), unit(u) {};
Item::~Item() {};

int Item::getId() { return id; };
void Item::setId(int a) { id = a; };

string Item::getName() { return name; };
void Item::setName(const string& a) { name = a; };

int Item::getQuantity() { return quantity; };
void Item::setQuantity(int a) { quantity = a; };

string Item::getUnit() { return unit; };
void Item::setUnit(const string& a) { unit = a; };

//PRODUCT

Product::Product() : Item(), price(0.0) {};
Product::Product(int id__, const string& n_, int q_, const string& u_, double p) : Item(id__, n_, q_, u_), price(p) {};
Product::~Product() {};

double Product::getPrice() { return price; };
void Product::setPrice(double a) { price = a; };

void Product::display() {
	cout << "Product: " << getId()<<" "<< getName() << " " << getQuantity() << " " << getUnit() << " " << getPrice() << " " << endl;
}

//BOM

BOM::BOM() :Item(), material(""), cost(0.0) {};
BOM::BOM(int id___, const string& n__, int q__, const string& u__, const string& m, double c) : Item(id___, n__, q__, u__), material(m), cost(c) {};
BOM::~BOM() {};


string BOM::getMaterial() { return material; };
void BOM::setMaterial(const string& a) { material = a; };

double BOM::getCost() { return cost; };
void BOM::setCost(double a) { cost = a; };

void BOM::display() {
	cout << getId() <<" "<< getName() << " " << getQuantity() << " " << getUnit() << " " << getCost() << " " << endl;
}

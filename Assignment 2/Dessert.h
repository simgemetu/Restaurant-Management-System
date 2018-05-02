#pragma once
#ifndef DESSERT_H
#define DESSERT_H
#define psize 50
#include "Food.h"
#include <iostream>
using namespace std;

enum dessert_type { NoDessert, Fruits, Icecream };

class Dessert : public Food {
protected:
	dessert_type dType;
	int pNum;
public:
	Dessert();
	Dessert(int ID, char *fname, int time, int kcal, int opt, char *country, float totalCost, dessert_type dessert, int plateNum);
	void setDessertType(dessert_type);
	dessert_type getDessertType();
	void setPlateNumber(int);
	int getPlateNumber();
	void calculateCost();
	void printFood();
};
#endif
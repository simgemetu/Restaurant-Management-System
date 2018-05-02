#pragma once
#ifndef APPETISER_H
#define APPETISER_H
#define psize 50
#include "Food.h"
#include <iostream>
using namespace std;

enum appetiser_type { NoAppetiser, Soup, Others };

class Appetiser : public Food {
protected:
	appetiser_type aType;
	int proCode;
public:
	Appetiser();
	Appetiser(int ID, char *fname, int time, int kcal, int opt, char *country, float totalCost, appetiser_type appetiserType, int code);
	void setAppetiserType(appetiser_type);
	appetiser_type getAppetiserType();
	void setPromotion(int);
	int getPromotion();
	void calculateCost();
	void printFood();
};
#endif
#pragma once

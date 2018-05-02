#pragma once
#ifndef MAIN_DISH_H
#define MAIN_DISH_H
#define psize 50
#include "Food.h"
#include <iostream>
using namespace std;

enum dish_type { Default, Meat, Chicken, Fish, Pasta, Wraps };

class Main_Dish : public Food {
protected:
	dish_type dType;
	double portion;
public:
	Main_Dish();
	Main_Dish(int ID, char *fname, int time, int kcal, int opt, char *country, double totalCost, dish_type foodType, double portionSize);
	void setType(dish_type);
	dish_type getType();
	void setPortion(double);
	double getPortion();
	void printFood();
};
#endif
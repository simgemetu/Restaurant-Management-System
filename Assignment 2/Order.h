#pragma once
#ifndef ORDER_H
#define ORDER_H
#define psize 50
#include "Food.h"
#include "Main_Dish.h"
#include "Dessert.h"
#include "Appetiser.h"
#include <iostream>
using namespace std;

class Order {
protected:
	int order_ID;
	char *customer;
	Food* proDish;
	Main_Dish m[psize];
	int mainDishCounter;
	Appetiser a[psize];
	int appetiserCounter;
	Dessert d[psize];
	int dessertCounter;
public:
	Order();
	Order(int, char*);
	void setOrderID(int);
	int getOrderID();
	void setCustomerName(char*);
	char *getCustomerName();
	void addNewAppetiser(Appetiser);
	void addNewDessert(Dessert);
	void addNewMainDish(Main_Dish);
	void listFoods();
	void printFoods();
	double calculateTotalCost();
	void searchAppetiserFood(int);
	void searchDessertFood(int);
	void searchMainDishFood(int);
};
#endif#pragma once

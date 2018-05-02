#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#ifndef RESTAURANT_H
#define RESTAURANT_H
#define psize 50
#include "Order.h"
#include <iostream>
using namespace std;

class Restaurant {
private:
	Order orders[psize];
	int orderCounter;
public:
	Restaurant();
	void addNewOrder(Order);
	void searchDetails(int, int);
	void printFoodAndPromotion();
	void printPromotionAndOther(int);
	void printAllCost();
	void printCost(int);
	void printOrderGrouped(int);
};
#endif
#pragma once

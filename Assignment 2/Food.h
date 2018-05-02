#pragma once
#ifndef FOOD_H
#define FOOD_H
#define psize 50
#include <iostream>
#include <string.h>
using namespace std;

class Food
{
protected:
	int food_id;
	char *food_name;
	int prep_time; //in minutes
	int calories;
	int isVegeterian;
	char *origin_country;
	double cost; //in $
public:
	Food();
	Food(int, char*, int, int, int, char*, double);
	Food(const Food& std);
	Food& operator=(const Food& std);
	~Food();
	void setFoodID(int);
	int getFoodID();
	void setFoodName(char*);
	char* getFoodName();
	void setPrepTime(int);
	int getPrepTime();
	void setCalories(int);
	int getCalories();
	void setOption(int);
	int getOption();
	void setOriginCountry(char*);
	char* getOriginCountry();
	void setCost(double);
	double getCost();
	void printFood();
};
#endif
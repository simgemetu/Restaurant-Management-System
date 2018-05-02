#include "Dessert.h"

Dessert::Dessert() { //default constructor
	dType = Fruits;
	pNum = 0;
}

Dessert::Dessert(int ID, char *fname, int time, int kcal, int opt, char *country, float totalCost, dessert_type dessert, int plateNum):Food(ID, fname, time, kcal, opt, country, totalCost)
{ //constructor for initialization
	dType = dessert;
	pNum = plateNum;
}

void Dessert::setDessertType(dessert_type dessert) {
	dType = dessert;
}

dessert_type Dessert::getDessertType() {
	return dType;
}

void Dessert::setPlateNumber(int plateNum) {
	pNum = plateNum;
}

int Dessert::getPlateNumber() {
	return pNum;
}

void Dessert::calculateCost() {
	cost = cost * pNum;
}

void Dessert::printFood() {
	int option1, option2;
	cout << "ID: " << food_id << endl;
	cout << "FoodName : " << food_name << endl;
	cout << "Prep Time: " << prep_time << endl;
	cout << "Calories: " << calories << endl;
	cout << "Vegetarian: " << isVegeterian << endl;
	cout << "Origin Conutry: " << origin_country << endl;
	cout << "Cost: " << cost << endl;
	cout << "Dessert Type: (1)Fruits (2)Ice-cream: " << endl;
	cin >> option1;
	cout << "Number in plate: " << endl;
	cin >> option2;
}
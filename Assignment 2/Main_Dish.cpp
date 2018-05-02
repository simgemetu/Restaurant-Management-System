#include "Main_Dish.h"

Main_Dish::Main_Dish() { //default constructor
	dType = Meat;
	portion = 0; //instead of N/A I initialized as 0
}

Main_Dish::Main_Dish(int ID, char *fname, int time, int kcal, int opt, char *country, double totalCost, dish_type foodType, double portionSize):Food(ID, fname, time, kcal, opt, country, totalCost)
{ //constructor for initialization
	dType = foodType;
	portion = portionSize;
}

void Main_Dish::setType(dish_type foodType) {
	dType = foodType;
}

dish_type Main_Dish::getType() {
	return dType;
}

void Main_Dish::setPortion(double portionSize) {
	portion = portionSize;
}

double Main_Dish::getPortion() {
	return portion;
}

void Main_Dish::printFood() {
	int option1, option2;
	cout << "ID: " << food_id << endl;
	cout << "FoodName : " << food_name << endl;
	cout << "Prep Time: " << prep_time << endl;
	cout << "Calories: " << calories << endl;
	cout << "Vegetarian: " << isVegeterian << endl;
	cout << "Origin Conutry: " << origin_country << endl;
	cout << "Cost: " << cost << endl;
	cout << "Type: " << endl;
	cout << "(1)Meat (2)Chicken (3)Fish (4)Pasta (5)Wraps" << endl;
	cin >> option1;
	cout << "Portion (1/1.5/0.75): " << endl;
	cin >> option2;
}
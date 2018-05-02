#include "Food.h"

Food::Food() {	//default constructor
	food_id = 0;
	food_name = new char[psize];
	strcpy(food_name, "Not Provided!");

	prep_time = 0;
	calories = 0;
	isVegeterian = 0;

	origin_country = new char[psize];
	strcpy(origin_country, "Not Provided!");

	cost = 0.0;
}

Food::Food(int ID, char *fname, int time, int kcal, int opt, char *country, double totalCost) { //constructor for initialization
	food_id = ID;
	food_name = new char[psize];
	strcpy(food_name, fname);

	prep_time = time;
	calories = kcal;

	isVegeterian = opt;

	origin_country = new char[psize];
	strcpy(origin_country, country);

	cost = totalCost;
}

Food::Food(const Food& std) {	//copy constructor
	food_id = std.food_id;

	food_name = new char[psize];
	strcpy(food_name, std.food_name);

	prep_time = std.prep_time;
	calories = std.calories;
	isVegeterian = std.isVegeterian;

	origin_country = new char[psize];
	strcpy(origin_country, std.origin_country);

	cost = std.cost;
}

Food& Food::operator=(const Food& std) { //assignment operator
	if (this == &std)
		return *this;

	food_name = new char[100];
	strcpy(food_name, std.food_name);

	prep_time = std.prep_time;
	calories = std.calories;
	isVegeterian = std.isVegeterian;

	origin_country = new char[psize];
	strcpy(origin_country, std.origin_country);

	cost = std.cost;
	return *this;
}

Food::~Food(void) { //destructor
	delete[] food_name;
	delete[] origin_country;
}

void Food::setFoodID(int ID) {
	food_id = ID;
}

int Food::getFoodID() {
	return food_id;
}

void Food::setFoodName(char *fName) {
	strcpy(food_name, fName);
}

char* Food::getFoodName() {
	return food_name;
}

void Food::setPrepTime(int time) {
	prep_time = time;
}

int Food::getPrepTime() {
	return prep_time;
}

void Food::setCalories(int kcal) {
	calories = kcal;
}

int Food::getCalories() {
	return calories;
}

void Food::setOption(int opt) {
	isVegeterian = opt+1;
}

int Food::getOption() {
	return isVegeterian;
}

void Food::setOriginCountry(char *country) {
	strcpy(origin_country, country);
}

char* Food::getOriginCountry() {
	return origin_country;
}

void Food::setCost(double totalCost) {
	cost = totalCost;
}

double Food::getCost() {
	return cost;
}

void Food::printFood() {
	cout << "ID: " << food_id << endl;
	cout << "FoodName : " << food_name << endl;
	cout << "Prep Time: " << prep_time << endl;
	cout << "Calories: " << calories << endl;
	cout << "Vegetarian: " << isVegeterian << endl;
	cout << "Origin Conutry: " << origin_country << endl;
	cout << "Cost: " << cost << endl;
}

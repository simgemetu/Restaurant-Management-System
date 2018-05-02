#include "Appetiser.h" 

Appetiser::Appetiser() { //default constructor
	aType = Soup;
	proCode = 0;
}

Appetiser::Appetiser(int ID, char *fname, int time, int kcal, int opt, char *country, float totalCost, appetiser_type appetiserType, int code):Food(ID, fname, time, kcal, opt, country, totalCost)
{ //constructor for initialization
	aType = appetiserType;
	proCode = code;
}

void Appetiser::setAppetiserType(appetiser_type appetiserType) {
	aType = appetiserType;
}

appetiser_type Appetiser::getAppetiserType() {
	return aType;
}

void Appetiser::setPromotion(int code) {
	proCode = code;
}

int Appetiser::getPromotion() {
	return proCode;
}

void Appetiser::calculateCost() {
	if (proCode == 1 || proCode == 2 || proCode == 3)
	{
		if (proCode == 1) {
			if (aType == Soup)
				cost -= cost * 0.1;
			else
				cost -= cost * 0.05;
		}
		else if (proCode == 2) {
			if (aType == Soup)
				cost -= cost * 0.2;
			else
				cost -= cost * 0.1;
		}
		else if (proCode == 3) {
			if (aType == Soup)
				cost -= cost * 0.3;
			else
				cost -= cost * 0.15;
		}
	}
}

void Appetiser::printFood() {
	int option1, option2;
	cout << "ID: " << food_id << endl;
	cout << "FoodName : " << food_name << endl;
	cout << "Prep Time: " << prep_time << endl;
	cout << "Calories: " << calories << endl;
	cout << "Vegetarian: " << isVegeterian << endl;
	cout << "Origin Conutry: " << origin_country << endl;
	cout << "Cost: " << cost << endl;
	cout << "Appetiser Type (1) Soups (2) Other: " << endl;
	cin >> option1;
	cout << "Promotion Code(0 / 1 / 2 / 3): " << endl;
	cin >> option2;
}
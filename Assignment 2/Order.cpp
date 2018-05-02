#include "Order.h"

Order::Order() { // default constructor
	order_ID = 0;
	customer = new char[psize];
	strcpy(customer, "");

	mainDishCounter = 0;
	appetiserCounter = 0;
	dessertCounter = 0;
}

// A constructor to initialise the Order ID name and Name of the person ordering
Order::Order(int orderIDname, char *customerName) {
	order_ID = orderIDname;

	customer = new char[psize];
	strcpy(customer, customerName);

	mainDishCounter = 0;
	appetiserCounter = 0;
	dessertCounter = 0;
}

void Order::setOrderID(int orderIDname) { // setter for the Order ID name
	order_ID = orderIDname;
}

int Order::getOrderID() { // getter for the Order ID name
	return order_ID;
}

void Order::setCustomerName(char *customerName) { // setter for the name of the person ordering
	strcpy(customer, customerName);
}

char* Order::getCustomerName() { // getter for the name of the person ordering
	return customer;
}

void Order::addNewAppetiser(Appetiser currentFood) { // Add new appetiser to order
	if (appetiserCounter < psize)
		a[appetiserCounter++] = currentFood;
}

void Order::addNewDessert(Dessert currentFood) { // Add new dessert to order
	if (dessertCounter < psize)
		d[dessertCounter++] = currentFood;
}

void Order::addNewMainDish(Main_Dish currentFood) { // Add new main dish to order
	if (mainDishCounter < psize)
		m[mainDishCounter++] = currentFood;
}

// List the food and the promotion dish (just show the cheapest in case order cost more than $100)
void Order::listFoods() {
	double totalcost = this->calculateTotalCost();
	if (totalcost >= 100) {
		int cheapestIndex_a = 0, cheapestIndex_d = 0, cheapestIndex_m = 0;

		for (int i = 0; i < appetiserCounter; i++) {
			a[i].calculateCost();
			if (a[i].getCost() < a[cheapestIndex_a].getCost())
				cheapestIndex_a = i;
		}
		for (int i = 0; i < dessertCounter; i++) {
			d[i].calculateCost();
			if (d[i].getCost() < d[cheapestIndex_d].getCost())
				cheapestIndex_d = i;
		}
		for (int i = 0; i < mainDishCounter; i++) {
			if (m[i].getCost() < m[cheapestIndex_m].getCost())
				cheapestIndex_m = i;
		}

		//Find the product with minimum cost to be a promotion dish
		proDish = &a[cheapestIndex_a];
		if (proDish->getCost() > d[cheapestIndex_d].getCost())
			proDish = &d[cheapestIndex_a];
		if (proDish->getCost() > m[cheapestIndex_m].getCost())
			proDish = &m[cheapestIndex_a];

		cout << "Promotion Dish" << endl;
		proDish->printFood();
	}
	else
		cout << "No promotion food" << endl;

	this->printFoods();
}

// Print names of food grouped as appetisers, main dishes, and desserts (total cost of each group separately)
void Order::printFoods() {
	for (int i = 0; i < appetiserCounter; i++)
		a[i].printFood();
	for (int i = 0; i < dessertCounter; i++)
		d[i].printFood();
	for (int i = 0; i < mainDishCounter; i++)
		m[i].printFood();
}

// Calculate the cost of each food type seperately 
double Order::calculateTotalCost() {
	double totalPrice = 0;

	for (int i = 0; i < appetiserCounter; i++) {
		a[i].calculateCost();
		totalPrice += a[i].getCost();
	}
	for (int i = 0; i < dessertCounter; i++) {
		d[i].calculateCost();
		totalPrice += d[i].getCost();
	}
	for (int i = 0; i < mainDishCounter; i++) {
		totalPrice += m[i].getCost();
	}
	return totalPrice;
}

// A function to search if a given food (Food ID) is in the order. If the food is in the order, you need to print its details
void Order::searchAppetiserFood(int id) {
	for (int i = 0; i < appetiserCounter; i++) {
		if (a[i].getFoodID() == id) {
			cout << "The food has been found in the 1 given by " << customer << ".The details listed below" << endl;
			a[i].printFood();
		}
	}
}

void Order::searchDessertFood(int id) {
	for (int i = 0; i < dessertCounter; i++) {
		if (d[i].getFoodID() == id) {
			cout << "The food has been found in the 2 given by " << customer << ".The details listed below" << endl;
			d[i].printFood();
		}
	}
}

void Order::searchMainDishFood(int id) {
	for (int i = 0; i < mainDishCounter; i++) {
		if (m[i].getFoodID() == id) {
			cout << "The food has been found in the 0 given by " << customer << ".The details listed below" << endl;
			m[i].printFood();
		}
	}
}

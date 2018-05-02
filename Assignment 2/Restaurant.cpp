#include "Restaurant.h"

Restaurant::Restaurant() { // default constructor
	orderCounter = 0;
}

void Restaurant::addNewOrder(Order currentOrder) { // Add a new order
	if (orderCounter < psize)
		orders[orderCounter++] = currentOrder;
}

// Search for the details of a given food (with food ID)
void Restaurant::searchDetails(int id, int category) {
	if (category == 0) {
		for (int i = 0; i < orderCounter; i++)
			orders[i].searchMainDishFood(id);
	}
	else if (category == 1) {
		for (int i = 0; i < orderCounter; i++)
			orders[i].searchAppetiserFood(id);
	}
	else if (category == 2) {
		for (int i = 0; i < orderCounter; i++)
			orders[i].searchDessertFood(id);
	}
	else
		cout << "Invalid category [(0) Main Dish, (1) Appetiser, (2) Dessert]" << endl;
}

// Print the list of all food and the promotion dish of all orders in the restaurant
void Restaurant::printFoodAndPromotion() {
	for (int i = 0; i < orderCounter; i++) {
		cout << "Order ID: " << orders[i].getOrderID() << endl;
		orders[i].listFoods();
	}
}

// Print the promotion dish and other food of a given order(with Order ID)
void Restaurant::printPromotionAndOther(int id) {
	for (int i = 0; i < orderCounter; i++) {
		if (id == orders[i].getOrderID())
			orders[i].listFoods();
	}
}

// Print the cost of all the orders in the restaurant
void Restaurant::printAllCost() {
	double cost = 0.0;
	for (int i = 0; i < orderCounter; i++)
		cost += orders[i].calculateTotalCost();
	cout << "Total cost of all orders is: " << cost << endl;
}

void Restaurant::printCost(int id) { // Print the cost
	double cost = 0.0;
	for (int i = 0; i < orderCounter; i++) {
		if (orders[i].getOrderID() == id)
			cost += orders[i].calculateTotalCost();
	}
	cout << "Total cost: " << cost << endl;
}

// Print the cost of a given order (with Order ID)
void Restaurant::printOrderGrouped(int orderID) {
	for (int i = 0; i < orderCounter; i++) {
		if (orderID == orders[i].getOrderID())
			orders[i].printFoods();
	}
}

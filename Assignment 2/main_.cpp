// Simge Haksal 2079317
#include <iostream>
#include "Food.h"
#include "Main_Dish.h"
#include "Appetiser.h"
#include "Dessert.h"
#include "Order.h"
#include "Restaurant.h"
using namespace std;

int main()
{
	Restaurant* restaurant = new Restaurant();
	Order* myOrder = new Order(); // for new order

	/*Main_Dish *dish = new Main_Dish();
	dish->setFoodName("Test dish");
	myOrder->addNewMainDish(*dish);
	restaurant->addNewOrder(*myOrder);
	restaurant->printFoodAndPromotion();*/

	int command = 0, var, id;
	char option, *answer;
	answer = new char[psize];

	while (command != 8)
	{
		fflush(stdin);
		cout << "Welcome to Restaurant Management System!" << endl;
		cout << "----------------------------------------" << endl;
		cout << "1. Create an order" << endl;
		cout << "2. Search a food by ID" << endl;
		cout << "3. List all foods ordered in the restaurant" << endl;
		cout << "4. Show total cost orders for the restaurant" << endl;
		cout << "5. List all food of a given order" << endl;
		cout << "6. List all food of a given order grouped as;" << endl;
		cout << "Appetisers, Main Dishes, and Desserts with total cost of each group." << endl;
		cout << "7. Show total cost of a given order" << endl;
		cout << "8. Exit" << endl;
		cout << "----------------------------------------" << endl;
		cout << "Enter your selection: " << endl;
		cin >> command;
		fflush(stdin);

		if (command == 1) {
			cout << "Your choice: " << command << endl;
			cout << "Enter the name for the order: " << endl;
			cin >> answer;
			myOrder->setCustomerName(answer);
			cout << "Enter order ID: " << endl;
			cin >> var;
			fflush(stdin);
			myOrder->setOrderID(var);
			cout << "Would you like to add a new food to the order (Y / N):" << endl;
			cin >> option;
			while (option != 'N') {
				cout << "(0) Main Dish" << endl;
				cout << "(1) Appetiser" << endl;
				cout << "(2) Dessert" << endl;
				cout << "Select food category: " << endl;
				cin >> var;
				if (var == 0) {
					char *name = new char[psize];
					strcpy(name, "Tavuk Dolma");
					char *country = new char[psize];
					strcpy(country, "Cyprus");
					Main_Dish *dish = new Main_Dish(11, name, 15, 850, 1, country, 40, Meat, 1);
					myOrder->addNewMainDish(*dish);
					myOrder->printFoods();
				}
				else if (var == 1) {
					char *name = new char[psize];
					strcpy(name, "Tavuk Dolma");
					char *country = new char[psize];
					strcpy(country, "Cyprus");
					Appetiser *dish = new Appetiser(11, name, 15, 850, 1, country, 40, Soup, 1);
					myOrder->addNewAppetiser(*dish);
					myOrder->printFoods();
				}
				else if (var == 2) {
					char *name = new char[psize];
					strcpy(name, "Tavuk Dolma");
					char *country = new char[psize];
					strcpy(country, "Cyprus");
					Dessert *dish = new Dessert(11, name, 15, 850, 1, country, 40, Fruits, 1);
					myOrder->addNewDessert(*dish);
					myOrder->printFoods();
				}
				restaurant->addNewOrder(*myOrder);
				cout << "The food has been added to the order successfully!" << endl;
				cout << "Would you like to add a new food to the order (Y / N): " << endl;
				cin >> option;
			}
		}
		else if (command == 2) {
			cout << "Your choice: " << command << endl;
			cout << "(0)Main Dish" << endl;
			cout << "(1)Appetiser" << endl;
			cout << "(2)Dessert" << endl;
			cout << "Please indicate the category: " << endl;
			cin >> var;
			cout << "Enter Food ID" << endl;
			cin >> id;
			restaurant->searchDetails(id, var);
		}
		else if (command == 3) {
			cout << "Your choice: " << command << endl;
			cout << "Food Details" << endl;
			restaurant->printFoodAndPromotion();
		}
		else if (command == 4) {
			cout << "Your choice: " << command << endl;
			restaurant->printAllCost();
		}
		else if (command == 5) {
			cout << "Your choice: " << command << endl;
			cout << "Enter order ID: ";
			cin >> var;
			fflush(stdin);
			restaurant->printPromotionAndOther(var);
		}
		else if (command == 6) {
			cout << "Your choice: " << command << endl;
			cout << "Please enter order ID: ";
			cin >> var;
			fflush(stdin);
			restaurant->printOrderGrouped(var);
			cout << "Food Details" << endl;
		}
		else if (command == 7) {
			cout << "Your choice: " << command << endl;
			cout << "Please enter order ID: ";
			cin >> var;
			fflush(stdin);
			restaurant->printCost(var);
		}
		else if (command == 8) {
			cout << "Your choice: " << command << endl;
			cout << "Goodbye!" << endl;
			cout << "Press any key to continue . . ." << endl;
		}
		else
			cout << "Invalid command!" << endl;
	}

	system("PAUSE");
	return 0;
}

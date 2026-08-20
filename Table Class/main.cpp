//Khuyen Nguyen CS163-001 Program #5 12/9/2025
//This is my main file where I will implement a menu interface to test 
//my table class and its operations

#include "graph.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	table my_table;
	place to_add;
	int choice = -1;

	do
	{
		cout << "1. Add a new fav place (vertex)" << endl;
		cout << "2. Connect two places (edge)" << endl;
		cout << "3. Display places connected to a given place" << endl;
		cout << "4. Display all" << endl;
		cout << "Enter 0 to quit program" << endl;
		cout << "Choice: " << endl;
		cout << "------------------------" << endl;
		cin >> choice;
		cin.ignore(100, '\n');

		if(choice == 1)
		{
			cout << "Enter name of place: " << endl;
			getline(cin, to_add.name);

			cout << "Enter the type of place (resturant, hike, arcade, etc.): " << endl;
			getline(cin, to_add.type);

			cout << "Enter rank for place (1 = best): " << endl;
			cin >> to_add.rank;
			cin.ignore(100, '\n');

			int result = my_table.insert_place(to_add);

			if(!result)
				cout << "Error, could not add place" << endl;
			else
				cout << "Place inserted" << endl;
		}
		else if(choice == 2)
		{
			string from_name;
			string to_name;

			cout << "Enter the name of the current place" << endl;
			getline(cin, from_name);

			cout << "Enter the name of the place to connect to" << endl;
			getline(cin, to_name);

			int edge_result = my_table.insert_edge(from_name, to_name);

			if(!edge_result)
				cout << "Error could not insert edge" << endl;
			else
				cout << "Edge inserted" << endl;
		}
		else if(choice == 3)
		{
			string current_name;

			cout << "Enter the name of the place to see its connection" << endl;
			getline(cin, current_name);

			int display_result = my_table.display_adj(current_name);

			if(!display_result)
				cout << "Error could not display" << endl;
			else
				cout << "Displayed: " << display_result << " places " << endl;
		}
		else if(choice == 4)
		{
			int disp_all = my_table.display_all();

			if(!disp_all)
				cout << "Error cannot display" << endl;
			else
				cout << "Display num of places: " << disp_all << endl;
		}
	}while (choice != 0);
	
	cout << "Goodbye" << endl;
	return 0;
}

			


//Khuyen Nguyen CS163-001 Program #5 12/9/2025
//This is my graph.cpp file where I implement my table class operations
//This is where any public memeber functions aswell as private functions reside
//Here I also have wrapper functions and helper functions too
#include "graph.h"
#include <string>
#include <iostream>

//Constructor for table class
table::table(int size)
{
	list_size = size;
	adjacency_list = new vertex[list_size];

	for (int i = 0; i < list_size; ++i)
	{
		adjacency_list[i].data = nullptr;
		adjacency_list[i].head = nullptr;
	}
}

//Insert new place
int table::insert_place(const place & to_add)
{
	for(int i = 0; i < list_size; ++i)
	{
		if(adjacency_list[i].data == nullptr)
		{
			adjacency_list[i].data = new place;

			adjacency_list[i].data->name = to_add.name;
			adjacency_list[i].data->type = to_add.type;
			adjacency_list[i].data->rank = to_add.rank;

			adjacency_list[i].head = nullptr;

			return 1;
		}
	}
	return 0;
}

//find location helper for insert edge
int table::find_location(const string & key_value) const
{
	for (int i = 0; i < list_size; ++i)
	{
		if(adjacency_list[i].data && adjacency_list[i].data->name == key_value)
			return i;
	}
	return -1;
}

//Insert edge
int table::insert_edge(const string & current_vertex, const string & to_attach)
{
	int from_index = find_location(current_vertex);
	int to_index = find_location(to_attach);

	if(from_index == -1 || to_index == -1)
		return 0;

	node * new_edge = new node;
	new_edge->adjacent = &adjacency_list[to_index];

	new_edge->next = adjacency_list[from_index].head;
	adjacency_list[from_index].head = new_edge;

	return 1;
}

//Display adj
int table::display_adj(const string & current_vertex) const
{
	int index = find_location(current_vertex);

	if(index == -1)
		return 0;

	node * current = adjacency_list[index].head;

	if(!current)
		return 0;

	int count = 0;

	while(current)
	{
		vertex * adj_vertex = current->adjacent; //neighbor vertex
		
		cout << "Name: " << adj_vertex->data->name << endl;
		cout << "Location type: " << adj_vertex->data->type << endl;
		cout << "Rank: " << adj_vertex->data->rank << endl;

		++count;
		current = current->next;
	}
	return count;
}

//Display all function
int table::display_all() const
{
	if(!adjacency_list)
		return 0;

	int count = 0;

	for(int i = 0; i < list_size; ++i)
	{
		if(adjacency_list[i].data)
		{
			cout << "Place #" << i + 1 << endl;
			cout << "Name: " << adjacency_list[i].data->name << endl;
			cout << "Location type: " << adjacency_list[i].data->type << endl;
			cout << "Rank: " << adjacency_list[i].data->rank << endl;
			cout << "----------------------" << endl;
			
			++count;
		}
	}
	return count;
}

//Remove all wrapper function
void table::remove_all()
{
	if(!adjacency_list)
		return;
	for(int i = 0; i < list_size; ++i)
	{
		remove_all(adjacency_list[i].head);

		if(adjacency_list[i].data)
		{
			delete adjacency_list[i].data;
			adjacency_list[i].data = nullptr;
		}
	}
}

//Remove all helper function
void table::remove_all(node *& head)
{
	if(!head)
		return;

	remove_all(head->next);
	delete head;
	head = nullptr;
}

//Destructor
table::~table()
{
	remove_all();
	delete [] adjacency_list;
	adjacency_list = nullptr;
	list_size = 0;
}



//Khuyen Nguyen 12/2/2025 Program #5 CS163-001
//This is my header file
//Here is where my struct place is with its data members 
//As well as my struct for my vertices and my struct for the nodes
//This is also where I implement my table class for the graph
#include <string>
using namespace std;

//struct place data members
struct place
{
	string name;
	string type;
	int rank;
};

//struct for my vertices
struct vertex
{
	place * data;
	struct node * head;
};

//Struct for my node
struct node
{
	vertex * adjacent;
	node * next;
};

//Graph implementation using table class
class table
{
	public:
		//constructor and destructor
		table(int size = 5);
		~table();
		//member functions
		int insert_place(const place & to_add);
		int insert_edge(const string & current_vertex, const string & to_attach);
		int display_all() const;
		int display_adj(const string & key_value) const;

	private:
		vertex * adjacency_list;
		int list_size;
		int find_location(const string & key_value) const;

		void remove_all();
		void remove_all(node *& head);
};




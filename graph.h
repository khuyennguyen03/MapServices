//Khuyen Nguyen 12/2/2025 Program #5 CS163-001
//This is my header file

//struct place data members
struct place
{
	char * name;
	char * info;
};


struct node
{
	vertex * adjacent;
	node * next;
};

struct vertex
{
	place * data;
	node * head;
};

class table
{
	public:
		//constructor and destructor
		table(int size = 5);
		~table();
		//member functions
		int insert_place(const place & to_add);
		int insert_edge(char * current_vertex, char * to_attach);
		int display_all() const;
		int display_adj(char * key_value);

		int find_location(char * key_value);

	private:
		vertex * adjacency_list;
		int list_size;

		int remove_all(node *& head);
}




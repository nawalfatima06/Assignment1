#include <iostream>
using namespace std;
struct node
{
	double data;
	node*next;
};
class list
{
private:
	node*head, *tail;
public:
	list();
	void createnode(double value);
	void display();
	void insert_start(double value);
	void insert_position(int pos, double value);
	void delete_first();
	void delete_last();
	void delete_position(int pos);
};
#include<iostream>
#include"linkedlist.h"
using namespace std;
int main()
{
	list obj;
	obj.createnode(25);
	obj.createnode(50);
	obj.createnode(90);
	obj.createnode(40);
	obj.createnode(55);
	cout << "\n.....................\n";
	cout << "\n......Displaying all nodes...............\n";
	cout << "\n.....................\n";
	obj.display();
	cout << "\n.....................\n";
	cout << "\n.....Inserting at End................\n";
	cout << "\n.....................\n";
	obj.createnode(15);
	obj.display();
	cout << "\n.....................\n";
	cout << "\n......Inserting at start...............\n";
	cout << "\n.....................\n";
	obj.insert_start(10);
	obj.display();
	cout << "\n.....................\n";
	cout << "\n.......inserting at particular..............\n";
	cout << "\n.....................\n";
	obj.insert_position(5, 60);
	obj.display();
	cout << "\n.....................\n";
	cout << "\n.......Deleting at Start..............\n";
	cout << "\n.....................\n";
	obj.delete_first();
	obj.display();
	cout << "\n.....................\n";
	cout << "\n.......Deleting at End..............\n";
	cout << "\n.....................\n";
	obj.delete_last();
	obj.display();
	cout << "\n.....................\n";
	cout << "\n.......Deleting at Particular..............\n";
	cout << "\n.....................\n";
	obj.delete_position(4);
	obj.display();
	cout << "\n.....................\n";
	cout << "\n......Adding at location 3...............\n";
	cout << "\n.....................\n";
	obj.insert_position(3,60);
	obj.display();
	cout << "\n.....................\n";

	system("pause");
	return 0;
}
list::list()
{
	head = NULL;
	tail = NULL;
}
void list::createnode(double value)
{
	node*temp = new node;
	temp->data = value;
	temp->next = NULL;
	if (head == NULL)
	{
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
}
void list::display()
{
	node*temp;
	temp = head;
	while (temp != NULL)
	{
		cout << temp->data << "\t";
		temp = temp->next;
	}
}
void list::insert_start(double value)
{
	node*temp = new node;
	temp->data = value;
	temp->next = head;
	head = temp;
}

void list::insert_position(int pos, double value)
{
	node*pre = new node;
	node*cur = new node;
	node*temp = new node;
	cur = head;
	for (int i = 1; i < pos; i++)
	{
		pre = cur;
		cur = cur->next;
	}
	temp->data = value;
	pre->next = temp;
	temp->next = cur;
}

void list::delete_first()
{
	node*temp = new node;
	temp = head;
	head = head->next;
	delete temp;
}

void list::delete_last()
{

	node * temp;
	temp = head;
	while (temp->next != tail)
	{
		temp = temp->next;
	}
	tail = temp;
	delete temp->next;
	tail->next = NULL;
}

void list::delete_position(int pos)
{
	node * temp = new node;
	node * cur= new node;
	cur = head;
	for (int i = 1; i < pos; i++)
	{
		temp = cur;
		cur = cur->next;
	}
	temp->next = cur->next;
	delete cur;
}
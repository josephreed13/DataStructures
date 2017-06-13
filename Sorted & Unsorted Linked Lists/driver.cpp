// Joseph Reed
// driver.cpp
// main function, sorted and unsorted linked lists,
// uses insertNode() and deleteNode(), prints

#include "student.h"
using namespace std;

int main() {
	// start linked list
	Student list;

	list.appendNode(2, "Jasmine", "3233 Rice Ave", 87.0);
	list.appendNode(1, "Terry", "1212 Almond Drive", 100.0);
	list.appendNode(4, "Paul", "3321 Greene Road", 54.1);
	list.appendNode(3, "Harry", "1234 Yellow Drive", 77.1);
	list.appendNode(6, "Elliot", "6978 Ford Road", 70.1);
	list.appendNode(5, "Bryan", "1111 Gay Road", 77.6);
	list.appendNode(8, "Ricardo", "3452 University Drive", 89.6);
	list.appendNode(7, "Kevin", "1422 Pope Ave" , 70.1);
	list.appendNode(10, "Steve", "2552 Red Road", 78.5);
	list.appendNode(9, "Nate", "6767 James Drive", 94.1);
	
	cout << "******************************************\n";
	cout << "Records from the unsorted linked list:" << endl;
	cout << "******************************************\n";
	
	list.displayList();
	cout << endl;

	Student list2;

	list2.insertNode(2, "Jasmine", "3233 Rice Ave", 87.0);
	list2.insertNode(1, "Terry", "1212 Almond Drive", 100.0);
	list2.insertNode(4, "Paul", "3321 Greene Road", 54.1);
	list2.insertNode(3, "Harry", "1234 Yellow Drive", 77.1);
	list2.insertNode(6, "Elliot", "6978 Ford Road", 70.1);
	list2.insertNode(5, "Bryan", "1111 Gay Road", 77.6);
	list2.insertNode(8, "Ricardo", "3452 University Drive", 89.6);
	list2.insertNode(7, "Kevin", "1422 Pope Ave" , 70.1);
	list2.insertNode(10, "Steve", "2552 Red Road", 78.5);
	list2.insertNode(9, "Nate", "6767 James Drive", 94.1);
	
	cout << "******************************************\n";
	cout << "Records from the sorted linked list:" << endl;
	cout << "******************************************\n";

	list2.displayList();
	
	cout << "Deleting 8th record...\n";
	list2.deleteNode(8);
	
	cout << "Inserting 11th record\n";
	list2.insertNode(11, "Jacob", "4432 Highway 6", 90.0);
	cout << endl;

	cout << "New array: \n";
	list2.displayList();
}
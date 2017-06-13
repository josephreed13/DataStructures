// Joseph Reed
// driver.cpp
// makes a linked list of student records, then pushes them 
// into the stack using the getRecord() function, then pops and 
// displays them

#include "student.h"
using namespace std;

int main() {
	// start linked list
	Student list;

	list.appendNode(2, "Jasmine", "3233 Rice Ave", 87.0);
	list.appendNode(1, "Terry", "1212 Almond Drive", 100);
	list.appendNode(4, "Paul", "3321 Greene Road", 54.1);
	list.appendNode(3, "Harry", "1234 Yellow Drive", 77.1);
	list.appendNode(6, "Elliot", "6978 Ford Road", 70.1);
	list.appendNode(5, "Bryan", "1111 Gay Road", 77.6);
	list.appendNode(8, "Ricardo", "3452 University Drive", 89.6);
	list.appendNode(7, "Kevin", "1422 Pope Ave" , 70.1);
	list.appendNode(10, "Steve", "2552 Red Road", 78.5);
	list.appendNode(9, "Nate", "6767 James Drive", 94.1);
	list.appendNode(12, "George", "512 Craddick", 91.1);
	list.appendNode(11, "Kelly", "76 Poland Drive", 64.4);
	list.appendNode(14, "Hannah", "800 Cash Place", 84.2);
	list.appendNode(13, "Ashley", "90210 Hollywood", 94.2);
	list.appendNode(15, "Storie", "1234 Aspen Road", 100.0);

	cout << "\ndisplaying linked list records:\n\n";
	list.displayList();
	cout << endl;

	int idCatch;
	string nameCatch;
	string addCatch;
	double dubCatch;


	DynIntStack stack;
	for(int i = 0; i < 15; i++) {
		list.getRecord(i, idCatch, nameCatch, addCatch, dubCatch);
		stack.push(idCatch, nameCatch, addCatch, dubCatch);
	}

	cout << "popping first 5 off of stack and displaying:\n\n";
	
	int idResult;
	string nameResult;
	string addressResult;
	double gradeResult;
	
	for(int i = 0; i < 5; i++) {
		stack.pop(idResult, nameResult, addressResult, gradeResult);
		cout << idResult << " " << nameResult << " ";
		cout << addressResult << " " << gradeResult << endl;
	}

	cout << "\ndisplaying the remaining records from the stack:\n\n";

	for(int i = 5; i < 15; i++) {
		stack.pop(idResult, nameResult, addressResult, gradeResult);
		cout << idResult << " " << nameResult << " ";
		cout << addressResult << " " << gradeResult << endl;
	}
}
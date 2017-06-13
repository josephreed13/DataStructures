// Joseph Reed
// Assignment 1
// student.cpp
// class member function definitions

#include "student.h"
using namespace std;

Student::Student() {
	head = NULL;
}

Student::~Student() {}

void Student::appendNode(int studentId, string studentName, string studentAddress, double studentGpa) {
	studentNode *newNode; //points to new node
	studentNode *nodePtr; //moves through list

	// allocate new node and set values
	newNode = new studentNode;
	newNode->id = studentId;
	newNode->name = studentName;
	newNode->address = studentAddress;
	newNode->gpa = studentGpa;
	newNode->next = NULL;

	if (!head)
		head = newNode;
	else {
		nodePtr = head;

		while(nodePtr->next)
			nodePtr = nodePtr->next;

		nodePtr->next = newNode;
	}
}

void Student::displayList() {
	studentNode *nodePtr; // moves through the list

	nodePtr = head;

	while(nodePtr) {
		cout << "-------------------------\n";
		cout << nodePtr->id << endl;
		cout << nodePtr->name << endl;
		cout << nodePtr->address << endl;
		cout << nodePtr->gpa << endl;
		cout << "-------------------------\n";
		
		nodePtr = nodePtr->next;
	}
}
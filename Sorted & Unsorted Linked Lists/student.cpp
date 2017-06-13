// Joseph Reed
// student.cpp
// class member function definitions

#include "student.h"
using namespace std;

Student::Student() {
	head = NULL;
}

Student::~Student() {}

void Student::insertNode(int studentId, string studentName, string studentAddress, double studentGpa) {
	studentNode *newNode;
	studentNode *nodePtr;
	studentNode *previousNode = NULL;

	newNode = new studentNode;
	newNode->id = studentId;
	newNode->name = studentName;
	newNode->address = studentAddress;
	newNode->gpa = studentGpa;

	if(!head) {
		head = newNode;
		newNode->next = NULL;
	}
	else {
		nodePtr = head;
		previousNode = NULL;

		while(nodePtr != NULL && nodePtr->id < studentId) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if(previousNode == NULL) {
			head = newNode;
			newNode->next = nodePtr;
		}
		else {
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

void Student::deleteNode(int studentId) {
	studentNode *nodePtr; //moves through list
	studentNode *previousNode;

	if(!head)
		return;

	if (head->id == studentId) {
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else {
		nodePtr = head;

		while(nodePtr != NULL && nodePtr->id != studentId) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if(nodePtr) {
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

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
// Joseph Reed
// RecordStack.cpp
// class member functions definitions
#include "RecordStack.h"
using namespace std;

RecStack::RecStack(int size) {
	stackArray = new Record[size];
	stackSize = size;
	top = -1;
}

RecStack::RecStack(const RecStack &obj) {
	if (obj.stackSize > 0)
		stackArray = new Record[obj.stackSize];
	else
		stackArray = NULL;

	stackSize = obj.stackSize;

	for(int i = 0; i < stackSize; i++)
		stackArray[i] = obj.stackArray[i];

	top = obj.top;
}

RecStack::~RecStack() {
	delete [] stackArray;
}

void RecStack::push(int idNum, string n, string a, double grade) {
	if(isFull()) 
		cout << "Stack is full \n";
	else {
		top++;
		stackArray[top].id = idNum;
		stackArray[top].name = n;
		stackArray[top].address = a;
		stackArray[top].avg = grade;
	}
}

void RecStack::pop(int &i, string &n, string &a, double &grade) {
	if(isEmpty())
		cout << "Stack is empty\n";
	else {
		i = stackArray[top].id;
		n = stackArray[top].name;
		a = stackArray[top].address;
		grade = stackArray[top].avg;
		top--; 
	}
}

bool RecStack::isFull() const {
	bool status;

	if(top == stackSize-1)
		status = true;
	else
		status = false;

	return status;
}

bool RecStack::isEmpty() const {
	bool status;

	if(top == -1)
		status = true;
	else 
		status = false;

	return status;
}
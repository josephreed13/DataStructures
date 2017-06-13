// Joseph Reed
// stack.cpp
// class member functions definitions
#include "stack.h"
using namespace std;

fixStack::fixStack(int size) {
	// dynamically allocate
	stackArray = new char[size];
	// initialize size and top
	stackSize = size;
	top = -1;
}

fixStack::~fixStack() {
	delete [] stackArray;
}

void fixStack::push(char entry) {
	// check if stack is full first
	if(isFull())
		cout << "The stack is already full!\n";
	else {
		top ++;
		stackArray[top] = entry;
	}
}

void fixStack::pop(char &val) {
	// check if stack is empty first
	if(isEmpty())
		cout << "The stack is empty!\n";
	else {
		val = stackArray[top];
		top--;
	}
}


bool fixStack::isFull() const {
	bool status;

	if(top == stackSize-1)
		status = true;
	else
		status = false;

	return status;
}

bool fixStack::isEmpty() const {
	bool status;

	if(top == -1)
		status = true;
	else 
		status = false;

	return status;
}

void fixStack::convert(string infix) {

	// holder for when values are popped
	char popVal;
	
	for(int i = 0; i < infix.length(); i++) {
		if(infix[i] == '(') {
			push(infix[i]);
		}
		else if(isalnum(infix[i])) {
			cout << infix[i] << " ";
		}
		else if(isOperator(infix[i])) {
			while(!isEmpty() && 
					stackArray[top] != '(' &&
					precedence(infix[i], stackArray[top]) != 1) {
				pop(popVal);
				cout << popVal << " ";
			}
			push(infix[i]);
		}
		else {
			do {
				pop(popVal);
				cout << popVal << " ";
			} while(stackArray[top] != '(');
		}
	}
	cout << endl;
}

bool fixStack::isOperator(char c) {
	if (c == '*' ||
		c == '/' ||
		c == '+' ||
		c == '-')
		return true;
	else
		return false;
}

int fixStack::getOperatorWeight(char op) {
	int weight = -1; 
	switch(op) {
		case '+':
		case '-':
			weight = 1;
			break;
		case '*':
		case '/':
			weight = 2;
			break;
	}
	return weight;
}

// see if left operator has precedence 
int fixStack::precedence(char op1, char op2) {
	int weight1 = getOperatorWeight(op1);
	int weight2 = getOperatorWeight(op2);

	int p;
	 
	if(weight1 > weight2) {
		p = 1;
		return p;
	}
	else if(weight1 < weight2) {
		p = 0;
		return p;
	}
	else {
		p = 2;
		return p;
	}
}
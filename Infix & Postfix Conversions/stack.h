// Joseph Reed
// stack.h
// class declaration
#include <iostream>
#include <cstddef>
#include <cctype>
using namespace std;

class fixStack {
private:
	char *stackArray;	//pointer to stack array
	int stackSize;		//size of stack
	int top;			//top of stack

public:
	fixStack(int);			//constructor
	~fixStack();			//destructor
	void push(char);	
	void pop(char &);
	bool isFull() const;
	bool isEmpty() const;
	void convert(string);
	bool isOperator(char);
	int getOperatorWeight(char);
	int precedence(char, char);
};
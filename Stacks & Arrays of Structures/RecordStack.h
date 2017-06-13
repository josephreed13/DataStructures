// Joseph Reed
// RecordStack.h
// class declaration
#include <iostream>
#include <fstream>
#include <cstddef>
using namespace std;

class RecStack {
private:
	struct Record {
		int id;
		string name;
		string address;
		double avg;
	};
	Record *stackArray;
	int stackSize;
	int top;

public:
	RecStack(int); // constructor
	RecStack(const RecStack &); // copy constructor
	~RecStack(); // destructor

	void push(int, string, string, double);
	void pop(int &, string &, string &, double &);
	bool isFull() const;
	bool isEmpty() const;
};
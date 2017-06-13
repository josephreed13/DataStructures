// Joseph Reed
// student.h
// class declaration 
#include <iostream>
#include <cstddef>
using namespace std;

class Student {
	private:
		struct studentNode {
			int id;
			string name;
			string address;
			double gpa;
			studentNode *next;
		};
		studentNode *head;
	public:
		//constructor
		Student();
		// destructor
		~Student();

		void appendNode(int, string, string, double);
		void insertNode(int, string, string, double);
		void deleteNode(int);
		void displayList();
		void getRecord(int, int &, string &, string &, double &);
};

class DynIntStack {
private:
	struct StackNode {
		int idNum;
		string sName;
		string sAddress;
		double sGrade;
		StackNode *next;
	};
	StackNode *top;
public:
	DynIntStack() {top = NULL;}
	~DynIntStack();
	void push(int, string, string, double);
	void pop(int &, string &, string &, double &);
	bool isEmpty();
};
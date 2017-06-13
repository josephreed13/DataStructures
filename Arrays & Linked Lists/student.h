// Joseph Reed
// Assignment 1
// student.h
// class declaration 
#include <iostream>
#include <cstddef>
#include <fstream>
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
		void displayList();
};
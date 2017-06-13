// Joseph Reed
// driver.cpp
// read in an infix expression and 
// output it as a postfix expression
// using stack

#include "stack.h"
using namespace std;

void displayInfix(string);

int main() {
	string infix1 = "3*X+(Y-12)-Z";
	cout << "-------------------------\n";
	cout << "Infix1:\n";
	displayInfix(infix1);
	cout << "Postfix1:\n";
	fixStack stack1(20);
	stack1.convert(infix1);
	cout << "-------------------------\n";
	cout << endl;

	string infix2 = "5*(3+Y)-X";
	cout << "-------------------------\n";
	cout << "Infix2:\n";
	displayInfix(infix2);
	cout << "Postfix2:\n";
	fixStack stack2(20);
	stack2.convert(infix2);
	cout << "-------------------------\n";
	cout << endl;

	string infix3 = "5*A+45-Z*2";
	cout << "-------------------------\n";
	cout << "Infix3:\n";
	displayInfix(infix3);
	cout << "Postfix3:\n";
	fixStack stack3(20);
	stack3.convert(infix3);
	cout << "-------------------------\n";
	cout << endl;

	string infix4 = "9*(3+Y)-3";
	cout << "-------------------------\n";
	cout << "Infix4:\n";
	displayInfix(infix4);
	cout << "Postfix4:\n";
	fixStack stack4(20);
	stack4.convert(infix4);
	cout << "-------------------------\n";
	cout << endl;

	string infix5 = "L+(Y+Z+15)-6";
	cout << "-------------------------\n";
	cout << "Infix5:\n";
	displayInfix(infix5);
	cout << "Postfix5:\n";
	fixStack stack5(20);
	stack5.convert(infix5);
	cout << "-------------------------\n";
	cout << endl;

	string infix6 = "R-78-(Y*13)";
	cout << "-------------------------\n";
	cout << "Infix6:\n";
	displayInfix(infix6);
	cout << "Postfix6:\n";
	fixStack stack6(20);
	stack6.convert(infix6);
	cout << "-------------------------\n";
	cout << endl;

	string infix7 = "T+42*(I+10)";
	cout << "-------------------------\n";
	cout << "Infix7:\n";
	displayInfix(infix7);
	cout << "Postfix7:\n";
	fixStack stack7(20);
	stack7.convert(infix7);
	cout << "-------------------------\n";
	cout << endl;

	string infix8 = "3*F-100*(U-7)";
	cout << "-------------------------\n";
	cout << "Infix8:\n";
	displayInfix(infix8);
	cout << "Postfix8:\n";
	fixStack stack8(20);
	stack8.convert(infix8);
	cout << "-------------------------\n";
	cout << endl;

	string infix9 = "K+7-(I*13)+2";
	cout << "-------------------------\n";
	cout << "Infix9:\n";
	displayInfix(infix9);
	cout << "Postfix9:\n";
	fixStack stack9(20);
	stack9.convert(infix9);
	cout << "-------------------------\n";
	cout << endl;

	string infix10 = "N/2+(X-1)";
	cout << "-------------------------\n";
	cout << "Infix10:\n";
	displayInfix(infix10);
	cout << "Postfix10:\n";
	fixStack stack10(20);
	stack10.convert(infix10);
	cout << "-------------------------\n";
	cout << endl;

	return 0;
}

void displayInfix(string infix) {
	for(int i = 0; i < infix.length(); i++)
		cout << infix[i] << " ";
	cout << endl;	
}
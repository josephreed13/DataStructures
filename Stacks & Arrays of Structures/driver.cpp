// Joseph Reed
// driver.cpp
// demonstrates the RecStack class
#include "RecordStack.h"
using namespace std;

struct Record {
	int i;
	string n;
	string a;
	double grade;
};

int main() {
	Record studentList[15];

	// populate array with ids
	studentList[0].i = 14;
	for(int j = 1; j < 14; j++) {
		studentList[j].i = j + 1;
	}
	studentList[14].i = 0;

	//file operations
    fstream dataFile;
    dataFile.open("records.txt", ios::in);
    if (dataFile.fail()) {
        cout << "Failed to open file....closing" << endl;
        return 0;
    }

    //populate array from dataFile
    for(int i = 0; i < 15; i++) {
        //read into values of array from file
        dataFile.ignore();
        getline(dataFile, studentList[i].n);
        dataFile >> studentList[i].grade;
    }

	//set address in array
	studentList[0].a = "2009 Hughes";
	studentList[1].a = "1404 Pine Tree";
	studentList[2].a = "1654 Amber Creek";
	studentList[3].a = "8516 Yellow Brick";
	studentList[4].a = "9021 Tanner Ave";
	studentList[5].a = "7985 Post Road";
	studentList[6].a = "1823 Westheimer";
	studentList[7].a = "9842 Richmond Ave";
	studentList[8].a = "5124 Craddock Ave";
	studentList[9].a = "1234 LBJ Drive";
	studentList[10].a = "5642 Sessoms Drive";
	studentList[11].a = "4587 Interstate 35";
	studentList[12].a = "1010 Ranch Road 12";
	studentList[13].a = "1632 Bass Road";
	studentList[14].a = "7415 Stick Drive";
	

	//display records from array
	cout << "********************************\n";
	cout << "Displaying records from array:\n";
	cout << "********************************\n";
	for(int i = 0; i < 15; i++) {
		cout << "-----------------------\n";
		cout << studentList[i].i << endl << studentList[i].n << endl;
		cout << studentList[i].a << endl << studentList[i].grade << endl;
		cout << "-----------------------\n";
	}
	cout << endl;
	// define stack to hold 15 records
	RecStack stack(15);
	

	//push array records into stack
	for(int i = 0; i < 15; i++)
		stack.push(studentList[i].i, studentList[i].n, studentList[i].a, studentList[i].grade);

	int catchI;
	string catchN, catchA;
	double catchGrade;

	// pop 5 records and display them
	cout << "***************************************\n";
	cout << "Popping 5 records and displaying:\n";
	cout << "***************************************\n";
	
	for(int k = 0; k < 5; k++) {
		stack.pop(catchI, catchN, catchA, catchGrade);
		cout << "--------------------------\n";
		cout << catchI << endl << catchN << endl << catchA 
			 << endl << catchGrade << endl;
		cout << "--------------------------\n";
	}
	
	cout << endl;
	// display remaining records
	cout << "******************************************\n";
	cout << "Popping remaining records and displaying:\n";
	cout << "******************************************\n";
	do {
		stack.pop(catchI, catchN, catchA, catchGrade);
		cout << "-------------------------\n";
		cout << catchI << endl << catchN << endl << catchA
			 << endl << catchGrade << endl;
		cout << "-------------------------\n";
	}while(!stack.isEmpty());

	return 0;
}
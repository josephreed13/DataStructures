// Joseph Reed
// driver.cpp
// main function, declares array and uses class 
// to declare linked list. prints both

#include "student.h"
using namespace std;

struct Record {
	int idNumber;
	string studentName;
	string studentAddress;
	double grade;
};

int main() {
	Record studentList[15];

	// populate array with ids
	studentList[0].idNumber = 14;
	for(int i = 1; i < 14; i++) {
		studentList[i].idNumber = i + 1;
	}
	studentList[14].idNumber = 0;

	// populate array with addresses
	studentList[0].studentAddress = "2009 Hughes";
	studentList[1].studentAddress = "1404 Pine Tree";
	studentList[2].studentAddress = "1654 Amber Creek";
	studentList[3].studentAddress = "8516 Yellow Brick";
	studentList[4].studentAddress = "9021 Tanner Ave";
	studentList[5].studentAddress = "7985 Post Road";
	studentList[6].studentAddress = "1823 Westheimer";
	studentList[7].studentAddress = "9842 Richmond Ave";
	studentList[8].studentAddress = "5124 Craddock Ave";
	studentList[9].studentAddress = "1234 LBJ Drive";
	studentList[10].studentAddress = "5642 Sessoms Drive";
	studentList[11].studentAddress = "4587 Interstate 35";
	studentList[12].studentAddress = "1010 Ranch Road 12";
	studentList[13].studentAddress = "1632 Bass Road";
	studentList[14].studentAddress = "7415 Stick Drive";


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
        getline(dataFile, studentList[i].studentName);
        dataFile >> studentList[i].grade;
    }

    cout << "**********************************************\n";
	cout << "The student records from the unsorted array:" << endl;
    cout << "**********************************************\n";

	for(int i = 0; i < 15; i++) {
		cout << "--------------------------------\n";
		cout << studentList[i].idNumber << endl;
		cout << studentList[i].studentName << endl;
		cout << studentList[i].studentAddress << endl;
		cout << studentList[i].grade << endl;
		cout << "--------------------------------\n";

	}

	Student list;

	list.appendNode(2, "Jasmine", "3233 Rice Ave", 87.0);
	list.appendNode(1, "Terry", "1212 Almond Drive", 100.0);
	list.appendNode(4, "Paul", "3321 Greene Road", 54.1);
	list.appendNode(3, "Harry", "1234 Yellow Drive", 77.1);
	list.appendNode(6, "Elliot", "6978 Ford Road", 70.1);
	list.appendNode(5, "Bryan", "1111 Gay Road", 77.6);
	list.appendNode(8, "Ricardo", "3452 University Drive", 89.6);
	list.appendNode(7, "Kevin", "1422 Pope Ave" , 70.1);
	list.appendNode(10, "Steve", "2552 Red Road", 78.5);
	list.appendNode(9, "Nate", "6767 James Drive", 94.1);

    cout << "\n**********************************************\n";
	cout << "The student records from the linked list:\n";
    cout << "**********************************************\n";
	list.displayList();
}
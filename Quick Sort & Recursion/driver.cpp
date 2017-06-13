// Joseph Reed
// driver.cpp
// main function, declares struct of student
// records and reads them into a vector. Then
// uses quick sort & recursion to sort vector

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstddef>
#include <cstdlib>
#include <ctime>
using namespace std;

//struct declaration
struct record {
    int id;
    string name;
    string address;
    double gpa;
    int *scorePtr;
};

//prototypes
int *getRandomScores(int);
int *applyScores(int *, int);
void quickSort(vector<record> &, int, int);
int partition(vector<record> &, int, int);
void swapInt(int &, int &);
void swapString(string &, string &);
void swapDouble(double &, double &);


int main() {

    //file operations
    fstream dataFile;
    dataFile.open("records.txt", ios::in);
    if (dataFile.fail()) {
        cout << "Failed to open file....closing" << endl;
        return 0;
    }

    //get 200 random test scores
    int size = 200;
    int *arrA = getRandomScores(size);
    
    //declare vector
    vector<record> sub;

    //declare counter for arrA index
    int n = 0;

    //populate vector from dataFile
    for(int i = 0; i < 20; i++) {
        //push back new record into vector
        sub.push_back(record());
        //read into values of vector from file
        dataFile >> sub[i].id;
        dataFile.ignore();
        getline(dataFile, sub[i].name);
        getline(dataFile, sub[i].address);
        dataFile >> sub[i].gpa;
        sub[i].scorePtr = applyScores(arrA, n);
        n += 10;
    }

    //output vector
    cout << "********************************\n";
    cout << "Unsorted Vector:\n";
    cout << "********************************\n";
    for(int k = 0; k < 20; k++) {
        cout << "------------------------\n";
        cout << sub[k].id << endl << sub[k].name << endl;
        cout << sub[k].address << endl << fixed << setprecision(1) << sub[k].gpa << endl;
        cout << "------------------------\n";
    }

    quickSort(sub, 0, 19);
    
    cout << endl << endl;
    cout << "********************************\n";
    cout << "Sorted Vector:\n";
    cout << "********************************\n";
    //output vector
    for(int k = 0; k < 20; k++) {
        cout << "------------------------\n";
        cout << sub[k].id << endl << sub[k].name << endl;
        cout << sub[k].address << endl << fixed << setprecision(1) << sub[k].gpa << endl;
        cout << "------------------------\n";
    }

    //deallocate random scores
    delete[] arrA;

    return 0;
}


int *getRandomScores(int size) {
    int *arr;
    
    //return null if size is zero or negative
    if (size <= 0)
        return NULL;

    //dynamically allocate the array
    arr = new int[size];

    //seed the random number generator
    srand(time(0));

    //populate the array with random numbers
    for(int i = 0; i < size; i++)
        arr[i] = rand() % 100;

    return arr;
}

int *applyScores(int *arr, int start) {
    int *newArr = new int[10];
    
        for(int i = 0; i < 10; i++) {
            newArr[i] = arr[start];
            start++;
        }
    
    return newArr;
}

void quickSort(vector<record> &set, int start, int end) {
    int pivotPoint;
    if (start < end) {
        //get the pivot point
        pivotPoint = partition(set, start, end);
        //sort first sublist
        quickSort(set, start, pivotPoint - 1);
        //sort second sublist
        quickSort(set, pivotPoint + 1, end);
    }
}

int partition(vector<record> &set, int start, int end) {
    int pivotValue, pivotIndex, mid;

    mid = (start + end) / 2;
    swapInt(set[start].id, set[mid].id);
    swapString(set[start].name, set[mid].name);
    swapString(set[start].address, set[mid].address);
    swapDouble(set[start].gpa, set[mid].gpa);

    pivotIndex = start;
    pivotValue = set[start].id;

    for(int scan = start + 1; scan <= end; scan++) {
        if (set[scan].id < pivotValue) {
            pivotIndex++;
            swapInt(set[pivotIndex].id, set[scan].id);
            swapString(set[pivotIndex].name, set[scan].name);
            swapString(set[pivotIndex].address, set[scan].address);
            swapDouble(set[pivotIndex].gpa, set[scan].gpa);
        }
    }

    swapInt(set[start].id, set[pivotIndex].id);
    swapString(set[start].name, set[pivotIndex].name);
    swapString(set[start].address, set[pivotIndex].address);
    swapDouble(set[start].gpa, set[pivotIndex].gpa);
    return pivotIndex;
}

void swapInt(int &value1, int &value2) {
    int temp = value1;
    value1 = value2; 
    value2 = temp;
}
void swapString(string &value1, string &value2) {
    string temp = value1;
    value1 = value2; 
    value2 = temp;
}
void swapDouble(double &value1, double &value2) {
    double temp = value1;
    value1 = value2; 
    value2 = temp;
}


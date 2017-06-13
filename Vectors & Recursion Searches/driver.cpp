// Joseph Reed
// driver.cpp
// main function, declares struct of student
// records and reads them into a vector. Then
// uses binary search & recursion to sort vector

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
int *getRandomIdForSearch(int);
int binarySearch(vector<record> &, int, int, int);


int main() {
    // counter variables
    int z = 0;    
    int n = 0;

    //file operations
    fstream dataFile;
    dataFile.open("records.txt", ios::in);
    if (dataFile.fail()) {
        cout << "Failed to open file....closing" << endl;
        return 0;
    }

    //get 200 random test scores
    int *arrA = getRandomScores(200);
    
    //declare vector
    vector<record> rec;

    //declare counter for arrA index

    //populate vector from dataFile
    for(int i = 0; i < 20; i++) {
        //push back new record into vector
        rec.push_back(record());
        //read into values of vector from file
        dataFile >> rec[i].id;
        dataFile.ignore();
        getline(dataFile, rec[i].name);
        getline(dataFile, rec[i].address);
        dataFile >> rec[i].gpa;
        rec[i].scorePtr = applyScores(arrA, n);
        n += 10;
    }

    cout << endl;
    cout << "************************\n";
    cout << "Vector of records:\n";
    cout << "************************\n";
    //output vector
    n = 10;

    for(int k = 0; k < 20; k++) {
        cout << endl << rec[k].id << endl << rec[k].name << endl;
        cout << rec[k].address << endl << fixed << setprecision(1) << rec[k].gpa << endl;
        cout << rec[k].name << "'s scores: \n";
        cout << "--------------------\n";
        for(int i = z; i < n; i++) {
            cout << arrA[i] << ", ";
        }
        z+=10;
        n+=10;
        cout << "\n--------------------\n";

    }
    cout << endl << endl;
    cout << "************************\n";
    cout << "Searches\n";
    cout << "************************\n\n\n";

    //get random id's to search
    int *idsToSearch = getRandomIdForSearch(3);
    int found;

    for(int i = 0; i < 3; i++) {
        cout << "Searching for: " << idsToSearch[i] << endl;
        found = binarySearch(rec, 0, 19, idsToSearch[i]);
        cout << "Result: \n";
        cout << "----------------------\n";
        cout << "Name: " << rec[found].name << endl;
        cout << "Address: " << rec[found].address << endl;
        cout << "GPA: " << fixed << setprecision(1) << rec[found].gpa << endl;
        cout << endl;
    }

    found = binarySearch(rec, 0, 19, 1019);
    cout << "Searching for ID at the end of the vector: \n";
    cout << "Result: " << found << endl;
    cout << "----------------------\n";
    cout << "Name: " << rec[found].name << endl;
    cout << "Address: " << rec[found].address << endl;
    cout << "GPA: " << fixed << setprecision(1) << rec[found].gpa << endl;
    cout << endl;

    found = binarySearch(rec, 0, 19, 1020);
    if(found == -1) {
        cout << "Searching for ID that is not in the vector: \n";
        cout << "Result: not found\n";
    }
    else 
        cout << "Found at: " << found << endl;
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

int *getRandomIdForSearch(int size) {
    int *holderArray = new int[100];

    srand(time(0));

    for(int i = 0; i < 100; i++)
        holderArray[i] = rand() % 20;

    int *searchArray = new int[size];
    int j = 0;

    for(int i = 0; i < size; i++) {
        if(holderArray[i] < 20 && j < 3) {
            searchArray[j] = holderArray[i] + 1000;
            j++;
        }
    }
    delete[] holderArray;
    return searchArray;
}

int binarySearch(vector<record> &rec, int first, int last, int value) {
    int middle; //midpoint of search

    if(first > last) 
        return -1;
    middle = (first + last) / 2;
    if(rec[middle].id == value)
        return middle;
    if(rec[middle].id < value) 
        return binarySearch(rec, middle+1, last, value);
    else 
        return binarySearch(rec, first, middle-1, value);

}
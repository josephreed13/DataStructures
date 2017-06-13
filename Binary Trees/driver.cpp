// Joseph Reed
// driver.cpp 
// main function. uses classes to work with
// binary search trees.

#include "IntBinaryTree.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstddef>
#include <cstdlib>
#include <ctime>
using namespace std;

// struct declaration
struct record {
    int id;
    string name;
    string address;
    double gpa;
    int *scorePtr;
};

// prototypes
void procedures(int);
int *getRandomScores(int);
int *applyScores(int *, int);

int main() {
	procedures(1);
	procedures(2);
    return 0;
}

void procedures(int num) {
	//file operations
    fstream dataFile;
	if(num == 1) {
    	dataFile.open("friends.txt", ios::in);
	    if (dataFile.fail()) {
	        cout << "Failed to open file....closing" << endl;
	        return;
	    }
	}
	else {
		dataFile.open("actors.txt", ios::in);
	    if (dataFile.fail()) {
	        cout << "Failed to open file....closing" << endl;
	        return;
	    }	
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

    // create binary tree
    IntBinaryTree tree;
	
	// populate tree with vector data    
    for(int i = 0; i < 20; i++)
    	tree.insertNode(sub[i].id, sub[i].name, sub[i].address, sub[i].gpa);

    // display the sorted tree
    cout << "\n********************************\n";
    cout << "Binary tree displayed in order:\n";
    cout << "********************************\n\n";
    tree.displayInOrder();

    // searches
    cout << "\n********************************\n";
    cout << "Searches:\n";
    cout << "********************************\n";
    cout << "\nSearching for id 1243....";
    tree.searchNode(1243);
    cout << endl;
    cout << "Searching for id 2345....";
    tree.searchNode(2345);
    cout << endl;

    // deletions
    cout << "\n********************************\n";
    cout << "Deletions:\n";
    cout << "********************************\n";
    cout << "Deleting record 3099....";
    tree.remove(3099);
    cout << "Deleted!\n";
    cout << "Deleting record 3398....";
    tree.remove(3398);
    cout << "Deleted!\n\n";

    // display
    cout << "\n********************************\n";
    cout << "Binary Tree after deletions:\n";
    cout << "********************************\n\n";
    tree.displayInOrder();

    //deallocate random scores
    delete[] arrA;

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

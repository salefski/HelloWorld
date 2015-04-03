//
//  main.cpp
//  HelloWorld
//
//  Created by Bill Salefski on 07-Feb-15.
//  Copyright (c) 2015 Bill Salefski. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int NUM_LINES = 4;
const int NUM_COLUMNS = 3;
const int COLUMN_WIDTH = 20;

void swap (int &a, int &b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void printArray (int a[], int len) {
    if((len<=1) || (a==nullptr)) return;
    int i;
    for(i=0;i<len;++i) {
        cout << "a[" << i << "]=" << a[i] << endl;
    }
    
}

void makeRandomArray (int a[], int len) {
    if((len<=1) || (a==nullptr)) return;
    int i;
    for(i=0;i<len;++i) {
        a[i] = rand() % 100;
    }
}

void insertionSort ( int a[], int len) {
    int i, j, x;
    if((len<=1 || a==nullptr)) {
        return;
      }
    
    for(i=1; i<=len-1; ++i) {
        x = a[i];
        j = i;
        while (j>0 && a[j-1] > x) {
            a[j] = a[j-1];
            j = j - 1;
            a[j] = x;
        }
    }
}

void createDataFile () {
    ofstream testFile("table-data.txt");
    if(testFile.is_open()) {
        testFile << 137 << " " << 2.71828 << endl;
        testFile << 42 << " " << 3.14159 << endl;
        testFile << 7897987 << " " << 1.608 << endl;
        testFile << 1337 << " " << 0.01101010001 << endl;
        testFile.close();
        cout << "file written" << endl;
    } else {
        cout << "unable to open file" << endl;
    }
    
}

void PrintTableBody() {
    ifstream input("table-data.txt");
    if(input.is_open()) {
        for(int k = 0; k < NUM_LINES; ++k) {
            int intValue;
            double doubleValue;
            input >> intValue >> doubleValue;
            cout << setw(COLUMN_WIDTH) << (k + 1) << " | ";
            cout << setw(COLUMN_WIDTH) << intValue << " | ";
            cout << setw(COLUMN_WIDTH) << doubleValue << endl;        }
        input.close();
    } else {
        cout << "Cannot open input file" << endl;
    }
}

void printTableHeader () {
    for (int column=0; column < NUM_COLUMNS-1; ++column) {
        cout << setfill('-') << setw(COLUMN_WIDTH) << "" << "-+-";
    };
    cout << setw(COLUMN_WIDTH) << "" << setfill(' ') << endl;
}

int main(int argc, const char * argv[]) {
    int a[10];
    makeRandomArray(a,10);
    printArray(a,10);
    insertionSort(a,10);
    printArray(a,10);
    return 0;
}

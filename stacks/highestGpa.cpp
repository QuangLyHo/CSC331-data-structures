//
//  main.cpp
//  stackApp
//
//  Created by Quang Ly Ho on 9/16/25.
//  Implementation of stack as an array

#include <iostream>
#include "stackType.hpp"
#include <fstream>
#include <string>

int main() {
    stackType<string> names(25);
    double highestGPA;
    double gpa;
    string name;
    ifstream inputFile("highestGpaData.txt");

    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open file!" << endl;
        return 1;
    }

    cout << fixed << showpoint;
    cout << setprecision(2);

    inputFile >> gpa >> name;

    highestGPA = gpa;

    while (inputFile) {
        if (highestGPA < gpa) {
            names.initializeStack();

            if (!names.isFullStack()) {
                names.push(name);
            }

            highestGPA = gpa;
        }
        else if (gpa == highestGPA){
            if (!names.isFullStack()) {
                names.push(name);
            }
            else {
                cout << "Stack overflows. " << "Program terminates!" << endl;
                return 1;
            }
        }
        inputFile >> gpa >> name;
    }

    cout << "The highest GPA = " << highestGPA << endl;
    cout << "The students holding the highest GPA: " << endl;

    while (!names.isEmptyStack()) {
        cout << names.top() << endl;
        names.pop();
    }

    cout << endl;

    inputFile.close();
    
    return 0;
}


////
//
// Name: Erik Tyrson
//
// Assignment: Employee Data
//
// Description: Does a thing :3
//
////
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

//PROTOTYPES
void readEmployeeData(int employeeData[50][8], string employeeNames[50]); //open/read the given employee file into arrays, add total hours worked for each employee

void sortEmployeeData(int employeeData[50][8], string employeeNames[50]); //sort the arrays based on total hours worked using bubble sort

void displayEmployeeData(int employeeData[50][8], string employeeNames[50]); //write out the processed and sorted data to console 

int main() 
{
    //CONSTANTS

    //VARIABLES

    //ARRAY
    int employeeData[50][8];
    string employeeNames[50];

    //PROCESS
    readEmployeeData(employeeData, employeeNames);

    //SORT
    sortEmployeeData(employeeData, employeeNames);

    //OUTPUT
    displayEmployeeData(employeeData, employeeNames);

    return 0;
}

//DEFINITIONS
void readEmployeeData(int employeeData[50][8], string employeeNames[50])
{
    ifstream fin;
    string file;
    
}

void sortEmployeeData(int employeeData[50][8], string employeeNames[50])
{

}

void displayEmployeeData(int employeeData[50][8], string employeeNames[50])
{

}

/*
    Test Outputs:

*/
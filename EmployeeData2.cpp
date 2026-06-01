/*
Name: Erik Tyrson

Program: EmployeeData2.cpp

Description: This program reads a given data file. It then stores the data in a vector of Employee structs.
The program then calculates the total hours worked for each employee and sorts the employees by total hours worked using
bubble sorting. Then, the program displays the employee data in a table, listing the employees in descending order by total
hours worked. The program then deallocates the dynamic memory and clears the vector before terminating.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// CONSTANTS
const int DAYS_IN_WEEK = 7;

// STRUCTS
struct Employee // struct to hold employee data
{
    string name;
    vector<int> hoursWorked; // hours worked each day of the week
    int totalHours; // total hours worked in the week
};

// FUNCTION PROTOTYPES
bool readEmployeeData(const string &fileName, vector<Employee *> &employees); // Function to read employee data from file and store in vector of Employee structs.
void createEmployee(const string &name, const vector<int> &hours, vector<Employee *> &employees); // Function to create a new Employee from dynamic memory for each employee read from file and add pointer to vector.
void recordTotalHours(Employee *emp); // Function to record total hours worked in the week and store it in the Employee struct.
void sortEmployeesByHours(vector<Employee *> &employees); // Function to sort employees by total hours worked in descending order.
void displayEmployeeData(const vector<Employee *> &employees); // Function to display employee data in tabular format.
void cleanup(vector<Employee *> &employees); // Function to deallocate dynamic memory used for Employee structs and clear vector.
void displayExitMessage(); // Function to display message indicating program is ending.

int main()
{
    // VARIABLES
    string fileName;

    // VECTORS
    vector<Employee *> employees; // vector to hold pointers to Employee structs

    // SCREEN CLEAR
    system("cls");

    // INPUT
    cout << "Enter employee data file name (or 'q' to quit): ";
    cin >> fileName;

    if (fileName == "q" || fileName == "Q")
    {
        displayExitMessage();
        return 0;
    }

    // PROCESS
    while (true) // Try to read data. If file name is invalid, ask again. Offer 'q' to quit option.
    {
        if (readEmployeeData(fileName, employees))
        {
            break; // Valid file name and data loaded, exit loop
        }

        cout << "Enter employee data file name (or 'q' to quit): ";
        cin >> fileName;

        if (fileName == "q" || fileName == "Q")
        {
            displayExitMessage();
            return 0;
        }
    }

    //// record total hours worked in the week and store it in the Employee struct.
    for (auto emp : employees)
    {
        recordTotalHours(emp);
    }
    
    sortEmployeesByHours(employees);

    // OUTPUT
    displayEmployeeData(employees);

    // CLEANUP
    cleanup(employees);

    displayExitMessage();

    return 0;
}

// FUNCTION DEFINITIONS
bool readEmployeeData(const string &fileName, vector<Employee *> &employees)
{
    // Open the file for reading
    ifstream inFile(fileName);
    
    // Check if the file was opened successfully
    if (!inFile)
    {
        cerr << "Error: Could not open file " << fileName << endl;
        return false;
    }

    // Read the number of employees first.
    int employeeCount = 0;
    if (!(inFile >> employeeCount))
    {
        cerr << "Error: Invalid file format. Missing employee count." << endl;
        return false;
    }

    // Read each employee record: name followed by 7 daily hour values.
    for (int employeeIndex = 0; employeeIndex < employeeCount; ++employeeIndex)
    {
        string name;
        if (!(inFile >> name))
        {
            cerr << "Error: Unexpected end of file while reading employee name." << endl;
            return false;
        }

        vector<int> hoursWorked;
        hoursWorked.reserve(DAYS_IN_WEEK);
        int hours = 0;

        for (int day = 0; day < DAYS_IN_WEEK; ++day)
        {
            if (!(inFile >> hours))
            {
                cerr << "Error: Invalid or missing hour value for " << name << "." << endl;
                return false;
            }
            hoursWorked.push_back(hours);
        }

        createEmployee(name, hoursWorked, employees);
    }

    inFile.close(); // Close the file after reading
    return true;
}

void createEmployee(const string &name, const vector<int> &hours, vector<Employee *> &employees)
{
    Employee *emp = new Employee; // Create a new Employee struct in dynamic memory
    emp->name = name; // Set employee name
    emp->hoursWorked = hours; // Set hours worked for each day
    recordTotalHours(emp); // Record total hours worked in the week and store it in the Employee struct
    employees.push_back(emp); // Add pointer to Employee struct to vector
}

void recordTotalHours(Employee *emp)
{
    emp->totalHours = 0; // Initialize total hours to 0
    for (const auto &hours : emp->hoursWorked)
    {
        emp->totalHours += hours; // Add hours worked for each day to total hours
    }
}

void sortEmployeesByHours(vector<Employee *> &employees)
{
    for (size_t pass = 0; pass < employees.size(); ++pass)
    {
        bool swapped = false;
        for (size_t i = 0; i + 1 < employees.size() - pass; ++i)
        {
            if (employees[i]->totalHours < employees[i + 1]->totalHours)
            {
                swap(employees[i], employees[i + 1]); // Keep highest totals toward the front
                swapped = true;
            }
        }

        if (!swapped)
        {
            break; // Already sorted
        }
    }
}

void displayEmployeeData(const vector<Employee *> &employees)
{
    cout << "Employee Weekly Hours:" << endl;
    cout << left << setw(15) << "Name" << "  S  M  T  W  T  F  S TTL" << endl;

    for (const auto &emp : employees)
    {
        cout << left << setw(15) << emp->name; // Display employee name
        for (const auto &hours : emp->hoursWorked)
        {
            cout << right << setw(3) << hours; // Display hours worked for each day
        }
        cout << right << setw(4) << emp->totalHours; // Display total hours
        cout << endl;
    }
}

void cleanup(vector<Employee *> &employees)
{
    for (auto emp : employees)
    {
        delete emp; // Deallocate memory for each Employee struct
    }
    employees.clear(); // Clear the vector after freeing memory
}

void displayExitMessage()
{
    cout << "Program is ending. Goodbye!" << endl;
}

/*
empdata3.txt results:

Enter employee data file name (or 'q' to quit): empdata3.txt
Employee Weekly Hours:
Name             S  M  T  W  T  F  S TTL
Kirk,James      10 10  0 10 12  0  0  42
Bosco,Sam        7  3  8  7  2  5  7  39
Rugg,James       7  3  8  7  2  5  7  39
VanPelt,Grace    5  6  5  6  5  6  5  38
Peters,Greg      5  6  5  6  5  6  5  38
Jane,Patrick     9  3  7  5  8  0  0  32
Lisbon,Teresa    2  3  8  3  6  3  5  30
Rigsby,Wayne     9 10  4  7  0  0  0  30
Lilly,Jack       2  3  8  3  6  3  5  30
Theiss,Bill      9 10  4  7  0  0  0  30
Cho,Kimball      8  8  3  0  8  2  0  29
Daniels,Carl     8  8  3  0  8  2  0  29
Minelli,Virgil   2  5  3  0  4  9  4  27
McCoy,Lenard     0  4  0  8  4  0  2  18
Scott,Annis      1  6  2  0  0  1  0  10
Program is ending. Goodbye!

//---------------------------------------------------------------//

empdata4.txt results:

Enter employee data file name (or 'q' to quit): empdata4.txt
Employee Weekly Hours:
Name             S  M  T  W  T  F  S TTL
Kirk,James      10 10  0 10 12  0  0  42
Ryan,Kevin       5  6  7  6  5  6  5  40
Leslie,Eddie     5  6  5  6  7  6  5  40
Uhura,Nyota     10 10  0  8 12  0  0  40
Bosco,Sam        7  3  8  7  2  5  7  39
Rugg,James       7  3  8  7  2  5  7  39
Chekov,Pavel     7  3  8  7  2  5  7  39
VanPelt,Grace    5  6  5  6  5  6  5  38
Peters,Greg      5  6  5  6  5  6  5  38
Parish,Lanie     7  3  8  6  2  5  7  38
Esposito,Javier  2  5  3  9  4  9  4  36
Beckett,Kate     2  8  8  3  6  3  5  35
Galloway,David   9 10  4  8  0  0  2  33
Jane,Patrick     9  3  7  5  8  0  0  32
Castle,Richard   4  3  7  5  8  0  5  32
Sulu,Hikaru      2  3  8  5  6  3  5  32
Lisbon,Teresa    2  3  8  3  6  3  5  30
Rigsby,Wayne     9 10  4  7  0  0  0  30
Lilly,Jack       2  3  8  3  6  3  5  30
Theiss,Bill      9 10  4  7  0  0  0  30
Montgo,Roy       9  2  4  7  0  0  8  30
Cho,Kimball      8  8  3  0  8  2  0  29
Daniels,Carl     8  8  3  0  8  2  0  29
Rodgers,Martha   8  7  3  0  8  2  0  28
Minelli,Virgil   2  5  3  0  4  9  4  27
Chapel,Christine  1  6  2  8  9  1  0  27
Kyle,John        8  8  3  0  2  2  0  23
McCoy,Lenard     0  4  0  8  4  0  2  18
Rand,Janice      0  4  0  8  3  0  2  17
Scott,Annis      1  6  2  0  0  1  0  10
Program is ending. Goodbye!
*/

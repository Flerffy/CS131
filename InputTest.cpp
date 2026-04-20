#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    int numCount = 0;
    int numSum = 0;
    double numAvg = 0;
    int i;

    // Create an ifstream object to read from the file
    ifstream fin;

    fin.open("infileL6.txt"); // open the file for reading

    if (fin.fail())
    {
        cout << "Error opening file" << endl;
        return 1;
    }

    // read the integers frm the file and update numCount, numSum, and numAvg accordingly
    while (fin >> i)
    {
        numCount++;
        numSum += i;
        numAvg = static_cast<double>(numSum) / numCount;
    }
        // add a gap
        cout << endl; 

        // Display the count, sum, and average of the integers read
        cout << "Count: " << numCount << ", Sum: " << fixed << setprecision(2) << numSum << ", Average: " << numAvg << endl;

    fin.close();
    return 0;
}
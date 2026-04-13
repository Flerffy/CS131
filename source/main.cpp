#include <iostream>
using namespace std;

////
// Name: Erik Tyrson
//
// Program Name: Change Machine
//
// Description:
//
//
//
//
//
////

int main()
{
    //// Declare variables
    // Declare variables for each type of coin
    double quarter = 0.25, dime = 0.10, nickel = 0.05, penny = 0.01, totalChange = 0.0, userInput = 0.0;
    int quarters = 0, dimes = 0, nickels = 0, pennies = 0;

    // Display welcome message and instructions
    cout << "Welcome to the Change Machine!" << endl;
    cout << "Please enter the amount of change you would like to receive in dollars (e.g., 1.25): ";

    // Get user input
    cin >> userInput;
    userInput = double(userInput); // Validate user input

    // Calculate change
    quarters = userInput / quarter;
    dimes = userInput / dime;
    nickels = userInput / nickel;
    pennies = userInput / penny;
    

    // Display change
    cout << "you will receive: "
            << quarters << " quarters, "
            << dimes << " dimes, "
            << nickels << " nickels, and "
            << pennies << " pennies." << endl;

    // Exit program

    cout << "Thank you for using the Change Machine!" << endl;
    cout << "Press any key to exit..." << endl;
    cin.get();
    return 0;
}
////
// Name: Erik Tyrson
//
// Project: Change Machine
//
// Description: This program calculates the change due
// by determining the number of quarters, dimes, nickels, and pennies
// that make up the change amount entered by the user.
// 
// By converting the amount to cents first, and then using division
// and modulus, the program can determine the number of each coin
// needed, starting with the largest denomination and working down
// the list. Finally, the program displays the number of each
// coin to be returned as change.
////
#include <iostream>
#include <string>
using namespace std;

int main()
{
 // Declare Variables
 double quarter = 0.25, dime = 0.10, nickel = 0.05, penny = 0.01;
 int quarters = 0, dimes = 0, nickels = 0, pennies = 0;
 double amount = 0.0;
 int remainingAmount = 0;

 // Get User Input
    cout << "Enter the amount paid (in dollars): ";
    cin >> amount;
 // Process User Input
    remainingAmount = static_cast<int>(amount * 100); // Convert to cents

    quarters = remainingAmount / static_cast<int>(quarter * 100);
    remainingAmount %= static_cast<int>(quarter * 100);

    dimes = remainingAmount / static_cast<int>(dime * 100);
    remainingAmount %= static_cast<int>(dime * 100);

    nickels = remainingAmount / static_cast<int>(nickel * 100);
    remainingAmount %= static_cast<int>(nickel * 100);

    pennies = remainingAmount / static_cast<int>(penny * 100);
    remainingAmount %= static_cast<int>(penny * 100);

 // Display Output
    cout << "Change to be returned:" << endl;
    cout << "Quarters: " << quarters << endl;
    cout << "Dimes: " << dimes << endl;
    cout << "Nickels: " << nickels << endl;
    cout << "Pennies: " << pennies << endl;

 // Prompt to Exit
    cout << "Press Enter to exit...";
    cin.ignore();
    cin.get();

 // End Program
    return 0;
 
}
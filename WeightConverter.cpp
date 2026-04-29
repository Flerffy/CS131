////
// Name: Eric Tyrson
//
// Project: Weight Converter
//
// Description: This program asks the user for a weight in pounds and ounces.
// It then converts the weight into kilograms and grams and displays the total weight
// as Kilograms with remaining grams. It achieves this by using functions to perform
// the conversions and output the results. Grams are rounded up to the nearest whole number.
////

#include <iostream>
#include <iomanip>

using namespace std;


// CONSTANTS
const double POUNDS_TO_OUNCES = 16.0, POUNDS_TO_GRAMS = 453.6, OUNCES_TO_GRAMS = 28.3495, GRAMS_TO_KILOGRAMS = 1000.0;

int main()
{
    // VARIABLES
    int pounds, kilograms, ounces, grams, totalGrams;

    // FUNCTION PROTOTYPES
    int promptAndGetInt(string prompt);
    int convertTotalGrams(int pounds, int ounces);
    void outputResults(int pounds, int ounces);

    // INPUT
        pounds = promptAndGetInt("Enter weight in pounds: ");
        ounces = promptAndGetInt("Enter weight in ounces: ");

    // PROCESSING
        // Convert weight from imperial to grams
        totalGrams = convertTotalGrams(pounds, ounces);

        // Take grams and remove every 1000, adding 1 to int kilograms for every 1000 grams, then take the remaining grams and output that as well
        kilograms = 0;
        for (; totalGrams >= 1000; totalGrams -= 1000)
        {
            kilograms++;
        }
        
        grams = totalGrams % 1000;


    // OUTPUT
        outputResults(pounds, ounces);
        cout << "Kilograms: " << kilograms << " kg" << endl;
        cout << "Grams: " << grams << " g" << endl;


    return 0;
}

// FUNCTION DEFINITIONS
int promptAndGetInt(string prompt) // Prompts the user for an integer and returns the value
{
    int value;
    cout << prompt;
    cin >> value;
    return value;
}

int convertTotalGrams(int pounds, int ounces) // Converts the weight in pounds and ounces into totalGrams and rounds up to the nearest whole number
{
    int totalGrams = static_cast<int>((pounds * POUNDS_TO_GRAMS) + (ounces * OUNCES_TO_GRAMS) + 0.5);
    return totalGrams;
}


void outputResults(int pounds, int ounces) // Outputs the weight in pounds and ounces
{
    cout << fixed << setprecision(2);
    cout << "Pounds: " << pounds << " lbs" << endl;
    cout << "Ounces: " << ounces << " oz" << endl;
}

////
// Test Outputs
// Enter weight in pounds: 5
// Enter weight in ounces: 4
// Pounds: 5 lbs
// Ounces: 4 oz
// Kilograms: 2 kg
// Grams: 381 g
////
// Enter weight in pounds: 13
// Enter weight in ounces: 11
// Pounds: 13 lbs 
// Ounces: 11 oz
// Kilograms: 6 kg
// Grams: 209 g
////
////
// Name: Eric Tyrson
//
// Project: Weight Converter
//
// Description: This program asks the user for a weight in pounds and ounces.
// It then converts the weight into kilograms and grams and displays the total weight
// as Kilograms with remaining grams. It achieves this by using functions to perform
// the conversions and output the results.
////

#include <iostream>
#include <iomanip>

using namespace std;


// CONSTANTS
const double POUNDS_TO_OUNCES = 16.0, POUNDS_TO_GRAMS = 453.592, OUNCES_TO_GRAMS = 28.349, GRAMS_TO_OUNCES = 0.035, GRAMS_TO_KILOGRAMS = 0.001, POUNDS_TO_KILOGRAMS = 0.453;

int main()
{
    // VARIABLES
    int pounds, kilograms, ounces, grams, totalKilograms, totalGrams;

    // FUNCTION PROTOTYPES
    int promptAndGetInt(string prompt);
    int convertTotalGrams(int pounds, int ounces);
    int convertTotalKilograms(int pounds, int ounces);
    int convertToKilograms(int pounds, int ounces);
    int convertToGrams(int pounds, int ounces);
    void outputResults(int pounds, int ounces);

    // INPUT
        pounds = promptAndGetInt("Enter weight in pounds: ");
        ounces = promptAndGetInt("Enter weight in ounces: ");

    // PROCESSING
        totalGrams = convertToGrams(pounds, ounces);
        totalKilograms = convertToKilograms(pounds, ounces);

    // OUTPUT
        outputResults(pounds, ounces);
        cout << "Kilograms: " << totalKilograms << " kg" << endl;
        cout << "Grams: " << totalGrams << " g" << endl;


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

int convertToKilograms(int pounds, int ounces) // Converts the weight in pounds and ounces to kilograms
{
    double convertedKilograms = (pounds * POUNDS_TO_KILOGRAMS) + (ounces * OUNCES_TO_GRAMS * GRAMS_TO_KILOGRAMS);
    return static_cast<int>(convertedKilograms);
}

int convertToGrams(int pounds, int ounces) // Converts the weight in pounds and ounces to grams
{
    double convertedKilograms = (pounds * POUNDS_TO_KILOGRAMS) + (ounces * OUNCES_TO_GRAMS * GRAMS_TO_KILOGRAMS);
    double convertedGrams = (static_cast<int>(convertedKilograms) * 1000) - (convertedKilograms * 1000);
    return static_cast<int>(convertedGrams);
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
// Pounds: 5.00 lbs
// Ounces: 4.00 oz
// Kilograms: 2 kg
// Grams: 267 g
////  
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
    int pounds, kilograms, ounces, grams;

    // FUNCTION PROTOTYPES
    int promptAndGetInt(string prompt);
    int convertToGrams(int pounds, int ounces);
    int convertToKilograms(int pounds, int ounces);
    void outputResults(int pounds, int   ounces);

    // INPUT
        pounds = promptAndGetInt("Enter weight in pounds: ");
        ounces = promptAndGetInt("Enter weight in ounces: ");

    // PROCESSING
        int totalGrams = convertToGrams(pounds, ounces);
        int totalKilograms = convertToKilograms(pounds, ounces);

    // OUTPUT
        outputResults(pounds, ounces);
        cout << "Total weight in kilograms: " << totalKilograms << " kg" << endl;
        cout << "Total weight in grams: " << totalGrams << " g" << endl;


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
    double totalKilograms = (pounds * POUNDS_TO_KILOGRAMS) + (ounces * OUNCES_TO_GRAMS * GRAMS_TO_KILOGRAMS);
    return static_cast<int>(totalKilograms);
}

int convertToGrams(int pounds, int ounces) // Converts the weight in pounds and ounces to grams
{
    double totalGrams = (pounds * POUNDS_TO_GRAMS) + (ounces * OUNCES_TO_GRAMS);
    return static_cast<int>(totalGrams);
}


void outputResults(int pounds, int ounces) // Outputs the weight in pounds and ounces
{
    cout << fixed << setprecision(2);
    cout << "Pounds: " << pounds << " lbs" << endl;
    cout << "Ounces: " << ounces << " oz" << endl;
}
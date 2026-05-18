/*
Name: Erik Tyrson

Assignment: MOO

Description: This program is a number guessing game called MOO.

The game starts with the program generating 4 unique random number between 1 and 9 at the start of the program
using the current time as a random seed. These numbers are stored in an array.

The user is prompted to enter up to 4 numbers between 1 and 9, separated by spaces. The program stores this input
in an array and compares it to the random numbers.

If the user guesses a correct number in the correct position, the program ouputs a 'B'.
If the user guesses a correct number in the wrong position, the program outputs a 'C'.
If the user does not guess any correct numbers, the program outputs an '!'.

Every time the user guesses, the program counts the number of tries and outputs the results of the guess.

If the user guesses all 4 numbers, and is give a "B B B B" result, the program outputs a congratulatory message and ends the game.

If the user guesses all 4 numbers in under 7 tries, the program outputs a special message congratulating the user on their impressive guessing skills.

If the user guesses all 4 numbers in 14 tries or more, the program outputs pity congratulations.

The player can end the game by typing quit instead of a guess, and the program will reveal the random numbers and end the game.
*/

#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function Prototypes
void genRandomNumber(int randomArray[]);
void getUserInput(int userArray[]);
void compareArrays(int randomArray[], int userArray[], char resultArray[]);



int main() 
{
    // Variables
    bool correctNum = false;
    bool correctPos = false;
    bool gameWon = false;

    int tries = 0;

    // Arrays
    int randomArray[4];
    int userArray[4];
    char resultArray[4];

    // Prompts
    cout << "Welcome to MOO!" << endl;
    cout << endl;
    cout << "I have picked 4 unique numbers between 1 and 9. Can you guess them?" << endl;
    cout << "For each correct number in the correct position, you will get a 'B'." << endl;
    cout << "For each correct number in the wrong position, you will get a 'C'." << endl;
    cout << "If you do not guess any correct numbers, you will get an '!'." << endl;
    cout << endl;

    genRandomNumber(randomArray); // Generate random numbers and store in randomArray

    getUserInput(userArray); // Get user input and store in userArray

    compareArrays(randomArray, userArray, resultArray); // Compare the two arrays and store results in resultArray

    // quit option
    if (userArray[0] == -1) // If user enters -1, end the game and reveal the random numbers
    {
        cout << "So long, cowboy. The random numbers were: ";
        for (int i = 0; i < 4; i++)
        {
            cout << randomArray[i] << " ";
        }
        cout << endl;
        return 0;
    }

    return 0;
}

// Function Definitions

void genRandomNumber(int randomArray[]) // Generate 4 unique random numbers between 1 and 9 and store in randomArray every time the program is run.
{
    srand(time(0)); // Seed random number generator with current time

    for (int i = 0; i < 4; i++) // Generate 4 unique random numbers
    {
        bool unique = false;
        while (!unique) // Loop until a unique number is generated
        {
            int num = rand() % 9 + 1; // Generate random number between 1 and 9
            unique = true;
            for (int j = 0; j < i; j++) // Check for uniqueness
            {
                if (num == randomArray[j])
                {
                    unique = false;
                    break;
                }
            }
            if (unique) // If number is unique, store in randomArray
            {
                randomArray[i] = num;
            }
        }
    }
}

void getUserInput(int userArray[]) // Get 4 numbers from user and store in userArray. Check for uniqueness, range, and correct input type.
{
    bool validInput = false;

    while (!validInput) // Loop until valid input is received
    {
        cout << "Enter your guess (4 unique numbers between 1 and 9. Separate each number with a space): ";
        for (int i = 0; i < 4; i++)
        {
            cin >> userArray[i];
        }

        // Check for uniqueness, range, and correct input type
        validInput = true;
        for (int i = 0; i < 4; i++)
        {
            if (userArray[i] < 1 || userArray[i] > 9) // Check for range
            {
                validInput = false;
                break;
            }
            for (int j = 0; j < i; j++) // Check for uniqueness
            {
                if (userArray[i] == userArray[j])
                {
                    validInput = false;
                    break;
                }
            }
            if (!validInput)
            {
                break;
            }
        }

        if (!validInput) // If input is invalid, clear input stream and prompt again
        {
            cout << "Invalid input. Please enter 4 unique numbers between 1 and 9." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void compareArrays(int randomArray[], int userArray[], char resultArray[]) // Compares the random number with the user's input
{
    for (int i = 0; i < 4; i++)
    {
        resultArray[i] = '!'; // Initialize resultArray with '!' for no correct guesses
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (userArray[i] == randomArray[j]) // If user guess matches a random number
            {
                if (i == j) // If the position is also correct, mark as 'B'
                {
                    resultArray[i] = 'B';
                }
                else // If the position is incorrect, mark as 'C' if not already marked as 'B'
                {
                    if (resultArray[i] != 'B')
                    {
                        resultArray[i] = 'C';
                    }
                }
            }
        }
    }

    // Output results
    cout << "Result: ";
    for (int i = 0; i < 4; i++)
    {
        cout << resultArray[i] << " ";
    }
    cout << endl;
}

/* 
Play Results:


*/

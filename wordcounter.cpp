#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    //VARIABLES
    int wordCount = 0, wordLength = 0;
    string word, fileName;

    
    ifstream fin; // create an ifstream object to read from the file
    
    // greet the user and ask for the file name
    cout << setw(10) << "~WORD COUNTER~" << endl;
    cout << "Welcome to the Word Counter program!" << endl;
    cout << "Please enter the name of the file you would like to read: ";
    cin >> fileName;

    fin.open(fileName);
    if (!fin.is_open()) // check if file exists
    {
        cout << "Error opening file. Please make sure the file exists and try again." << endl;
        cin >> fileName; // ask for the file name again
        fin.open(fileName);
    
    // display file name acceptable
    cout << "File name accepted: " << fileName << endl;
    cout << "Counting words in the file..." << endl;

    // display the word count
    while (fin >> word)
    {
        // count total words in the file
        wordCount++;

        // calculate word length per word and sort them
        wordLength = word.length();
  
    }

    cout << setw(10) << "~Word Report for " << fileName << "~" << endl;

    // display two columns for Length and Count
    cout << setw(10) << "Length:" << setw(10) << "Count:" << endl;
    cout << setw(10) << "-------" << setw(10) << "------" << endl;
    // display number of words with a length of 1
    cout << setw(10) << wordLength << setw(10) << wordCount << endl;
    // display number of words with a length of 2
    cout << setw(10) << wordLength << setw(10) << wordCount << endl;
    // display number of words with a length of 3
    cout << setw(10) << wordLength << setw(10) << wordCount << endl;
    // display number of words with a length of 4
    cout << setw(10) << wordLength << setw(10) << wordCount << endl;
    // display number of words with a length of 5
    cout << setw(10) << wordLength << setw(10) << wordCount << endl;
    // display number of words with a length of 6
    cout << setw(10) << wordLength << setw(10) << wordCount << endl;
    // display number of words with a length of 7
    cout << setw(10) << wordLength << setw(10) << wordCount << endl;
    // display number of words with a length of 8
    cout << setw(10) << wordLength << setw(10) << wordCount << endl;


    cout << "The number of words in the file is: " << wordCount << endl;
    fin.close();

    return 0;
    }
}
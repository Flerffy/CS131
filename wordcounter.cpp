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

    int wordLengthCount[21] = {0}; // Array to store the count of words of each length (assuming max word length is 20)

    ifstream fin; // create an ifstream object to read from the file
    
    // greet the user and ask for the file name
    cout << setw(10) << "~WORD COUNTER~" << endl;
    cout << "Welcome to the Word Counter program!" << endl;
    cout << "Please enter the name of the file you would like to read: ";
    cin >> fileName;

    fin.open(fileName);
    while (!fin.is_open()) // check if file exists
    {
        cout << "Error opening file. Please make sure the file exists and try again." << endl;
        cin >> fileName; // ask for the file name again
        fin.open(fileName);
    }

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
        if (wordLength >= 9)
        {
            wordLength = 9; // group all words of length 9 or more together
        }
        wordLengthCount[wordLength]++;
    }

    cout << setw(10) << "~Word Report for " << fileName << "~" << endl;

    // display two columns for Length and Count
    cout << setw(10) << "Length:" << setw(10) << "Count:" << endl;
    cout << setw(10) << "-------" << setw(10) << "------" << endl;
    // display the word count for each word length
    for (int i = 1; i <= 8; i++)
    {
        cout << setw(10) << i << setw(10) << wordLengthCount[i] << endl;
    }
    cout << setw(11) << "9+" << setw(9) << wordLengthCount[9] << endl; // display count for words of length 9 or more

    cout << "The number of words in the file is: " << wordCount << endl;
    fin.close();
    fin.clear();

    return 0;
}

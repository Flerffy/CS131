#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Function Prototypes

int main() 
{
    int arr[10] = {0};
    int *ptr = arr;

    for (int i = 0; i < 10; i++)
    { 
        *ptr = i + 1;

        ptr++;
    }

    for (int i : arr) 
    {
        cout << i << " ";
    }

    return 0;
}

// Function Definitions
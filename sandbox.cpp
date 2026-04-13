#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand( time(nullptr));
    int i = 1;
    while (i <= 5)
    {
        cout << rand() << endl;
        ++i;
    }
    return 0;
}
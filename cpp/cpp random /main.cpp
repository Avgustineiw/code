#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{   
    cout << "    ";
    for (short i = 0; i < 10; i++)
    {
        cout << i << "    ";
    }

    for (short i = 65; i < 71; i++)
    {
        cout << char(i) << "    ";
    } 

    cout << endl;
    for (short i = 32; i < 128; i++) {
        if ((i == 32) || (i%16 == 0)) {
            cout << ((i+1)/16)-2 << "   ";
        }
        cout << char(i) << "    ";
        if ((i+1)%16 == 0) {
            cout << endl;
        }
    }
    return 0;
}
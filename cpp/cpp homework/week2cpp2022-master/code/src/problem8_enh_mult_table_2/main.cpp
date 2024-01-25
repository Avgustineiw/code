////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 8: "Enhanced Multiplication Table".
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       19.01.2021
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// Modification of the Problem 7 (Multiplication Table), where a user can
/// repeat a solution multiple times (write using the “do..while” loop).
///
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

int main()
{
    do {
    short m;
    short n;

    cout << "Enter the first value: "; 
    cin >> m;
    
    cout << "Enter the second value: ";
    cin >> n;

    if (n <= 0 || m <= 0) {
        break;
    }

    cout << "   ";

    for (short i = 1; i < n+1; i++)
    {
        cout << i << "  ";
    }
    cout << endl;

    for (short i = 1; i < m+1; i++)
    {
        for (short i_1 = 0; i_1 < n+1; i_1++)
        {
            if (i_1 != 0) {
                cout << i*i_1 << "  "; 
            }
            else {
                cout << i << "  ";
            }
        }
        cout << endl;
    }
    } while (true);
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 2: "Multiplication Table".
/// \author     Sergey Shershakov, Georgii Zhulikov
/// \version    0.2.0
/// \date       16.01.2023
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// Program asks a user for two numbers, 1 <= (m, n) <= 8 and prints a rectangle
/// multiplication table aligning output at tab positions.
///
/// Example:
/// 	1	2	3
/// 1	1	2	3
/// 2	2	4	6
/// 3	3	6	9
/// Note how in the first line tab automatically aligns positions.
/// 
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

int main()
{
    short m;
    short n;
    
    cin >> m;
    cin >> n;

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
    
    return 0;
}


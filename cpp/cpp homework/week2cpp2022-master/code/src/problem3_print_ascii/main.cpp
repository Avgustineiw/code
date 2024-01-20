////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 3: "Print ASCII table".
/// \author     Sergey Shershakov, Georgii Zhulikov
/// \version    0.2.0
/// \date       16.01.2023
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// Print the "printable part" of the ASCII table using tabs for aligning.
/// 
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

int main()
{
    // TODO: input your code here
    for (short i = 33; i < 128; i++) {
        cout << i << " " << char(i) << endl;
    }
    return 0;
}

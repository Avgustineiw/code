////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 6: "String indices".
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       19.01.2021
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// Work with operator[], and length() property. Consider valid indices of an
/// std::string object.
///
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;
//Cad, bra, brac, length of the string;
int main()
{
    // TODO: input your code here
    string str = "abracadabra";
    string s_1 = "";
    string s_2 = "";
    string s_3 = "";

    s_1 = s_1 + str.substr(1,3);
    cout << s_1 << " length: " << s_1.size() << endl;
    s_2 = s_2 + str.substr(1,4);
    cout << s_2 << " length: " << s_2.size() << endl;
    s_3 = s_3 + str.substr(4, 3);
    cout << s_3 << " length: " << s_3.size() << endl;

    return 0;
}

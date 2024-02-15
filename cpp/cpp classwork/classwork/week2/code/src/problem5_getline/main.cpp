////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 5: "Reading text strings using getline".
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       19.01.2021
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// Train reading text string with spaces and other special symbol using
/// cin.getline() for c-strings and std::getline() for std::string-s.
/// Then, consider the “read lines until first empty line” idiom.
///
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

//Code below reads lines from the user until the first empty line, then prints what was written.

int main()
{
    string temp = "";
    string str = "";

    while (getline(cin, temp)) {
        if (temp.empty()) {
            break;
        }
        str += temp + "\n";
    }
    cout << str;
    return 0;
}
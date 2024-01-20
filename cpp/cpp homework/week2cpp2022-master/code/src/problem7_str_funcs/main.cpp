////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 7: "Some functions for dealing with strings".
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       19.01.2021
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// Try to use functions for dealing with strings:
/// 1) strcmp, strlen for c-strings;
/// 2) string:: size(), length(), operator<, operator+, operator= etc for
///    std::string-s.
///
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

//The first bit of code compares c-strings and prints their length
//The second bit of code does the same, but with string-s. 

int main()
{
    // This is the code for c-style strings.    
    char str_1[] = "Hello World";
    char str_2[] = "Cat";
    int val;
    val = strcmp(str_1, str_2);
    if (val < 0) {
        cout << "string 1 is less than string 2" << endl;
    }
    else if (val > 0) {
        cout << "string 2 is less than string 1" << endl;
    }
    else {
        cout << "string 1 is equal to string 2" << endl;
    }

    cout << "The length of string 1 is: "<< strlen(str_1) << endl;
    cout << "The length of string 2 is: "<< strlen(str_2) << endl;


    // This is the code for string-s.
    string str_3 = "Hello world";
    string str_4 = "Cat";
    
    cout << "The size of string 1 is: " << str_3.size() << endl;
    cout << "The length of string 2 is: " << str_4.length() << endl;

    if (str_3 == str_4) {
        cout << "The strings are equal";
    }
    else if (str_3 > str_4) {
        cout << "String 4 is less than string 3";
    }
    else {
        cout << "String 3 is less than string 4";
    }
    return 0;
}



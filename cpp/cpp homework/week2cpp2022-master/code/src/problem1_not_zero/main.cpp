////////////////////////////////////////////////////////////////////////////////
/// 
/// Problem 1. Not zero.
/// 
/// Program asks a user for a number to use in expression 100/x
/// User enters a number.
/// If the number is not 0, program outputs the result.
/// If the number if 0, program prints "Cannot use 0"
///
////////////////////////////////////////////////////////////////////////////////

#include <string>
#include <iostream>
using namespace std;

int main()
{
    // TODO: input your code here
    short a;
    cin >> a;

    if (a == 0) {
        cout << "Cannot use 0";
    }
    else {
        cout << 100/a;
    }
    return 0;
}
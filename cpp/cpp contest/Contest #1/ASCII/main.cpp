#include <iostream>
using namespace std;

int main()
{   
    for (short i = 0; i < 10; i++)
    {
        cout << "\t" << i;
    }

    for (short i = 65; i < 71; i++)
    {
        cout << "\t" << char(i);
    } 

    cout << endl;
    for (short i = 32; i < 128; i++) {
        if ((i == 32) || (i%16 == 0)) {
            cout << ((i+1)/16) << "\t";
        }
        cout << char(i) << "\t";
        if ((i+1)%16 == 0) {
            cout << endl;
        }
    }
    return 0;
}
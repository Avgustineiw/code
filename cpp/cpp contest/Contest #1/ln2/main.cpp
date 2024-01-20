#include <iostream>
using namespace std;
//test
int main()
{
    int n;
    short sign = 1;
    float res = 0;

    cin >> n;

    for (float i = 1; i < n+1; i++) {
        res += (1 / i) * sign;
        sign = -sign;
    }
    cout << res << endl; 
    return 0;
}
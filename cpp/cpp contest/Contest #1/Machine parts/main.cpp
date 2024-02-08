#include <iostream>
using namespace std;

int main()
{
    int n, k, m, res = 0;

    cin >> n;
    cin >> k;
    cin >> m;
    if (m > k)
    {
        cout << 0 << endl;
        return 0;
    }
    
    while (n >= k) {
        res += (n / k) * (k / m);
        n -= (n / k) * (k / m) * m;
    }
    cout << res << endl;
    return 0;
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int day;
    int month;
    int year;
    short leap = 0;
    cin >> day;
    cin >> month;
    cin >> year;
    
    if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {
        leap = 1;
    }

    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (day >= 30) {
                day = (day + 2)-31;
                month += 1;
            }
            else {
                day += 2;
            }
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            if (day >= 29) {
                day = (day + 2)-30;
                month += 1;
            }
            break;

        case 2:
            if (day >= 27 + leap) {
                day = (day + 2)-(28+leap);
                month += 1;
            }
            else {
                day += 2;
            }
            break;
    }
    
    if (month == 13) {
        year += 1;
        month = 1;
    }
    cout << day << " " << month << " " << year << endl;
    return 0;
}
#include <iostream>
#include "clockType.h"

using namespace std;

int main() {
    clockType myClock;
    clockType londonClock;
    int h, m, s;

    cout << "Enter hours in your location\n";
    cin >> h;
    cout << "Enter minutes in your location\n";
    cin >> m;
    cout << "Enter seconds in your location\n";
    cin >> s;

    myClock.setTime(h, m, s);
    londonClock.setTime(h + 5, m, s);

    myClock.printTime();
    cout << endl;
    londonClock.printTime();
    cout << endl;

    cout << "\n== operator override\n";

    if (myClock == londonClock) {
        cout << "Equal\n\n";
    }
    else cout << "Not equal\n\n";

    return 0;
}
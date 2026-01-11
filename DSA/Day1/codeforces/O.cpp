#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    int Max, Min;
    if (x >= y && x >= z)
        Max = x;
    else if (y >= x && y >= z)
        Max = y;
    else
        Max = z;

    // Find Min
    if (x <= y && x <= z)
        Min = x;
    else if (y <= x && y <= z)
        Min = y;
    else
        Min = z;

    cout << "Min = " << Min << endl;
    cout << "Max = " << Max << endl;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    int a[] = {
        1,
        7,
        10,
        15,
        19,
        21
    };
    int b[] = {
        3,
        5,
        6,
        29,
        37,
        50
    };

    vector < int > c;
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    int i = 0;
    int j = 0;

    while (i < n && j < m) {

        if (a[i] < b[j]) {
            c.push_back(a[i]);
            i++;
        } else {
            c.push_back(b[j]);
            j++;

        }
    }
    while (i < n) {
        c.push_back(a[i]);
        i++;
    }
    while (j < m) {
        c.push_back(b[j]);
        j++;
    }


    for (auto num: c) {
        cout << num << " ";
    }

    return 0;

}
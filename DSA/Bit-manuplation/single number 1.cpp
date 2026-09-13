#include <bits/stdc++.h>

using namespace std;

int main() {
    long long t;
    cin >> t;

    int ans = 0;
    for (int i = 0; i < t; i++) {
        int A;
        cin >> A;

        ans ^= A;

    }
    cout << ans;

}
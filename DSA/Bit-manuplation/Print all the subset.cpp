#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int mask = 1; mask < (1 << n); mask++) {

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                cout << a[i] << " ";
            }
        }

        cout << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

bool checkIthBit(int num, int i) {
    long long mask = 1LL << i;
    if (num & mask) return true;
    else return false;
}
int setIthBit(int num, int i) {
    long long mask = 1LL << i;
    return num | mask;
}

int main() {
    int n;
    cin >> n;

    vector < long long > A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    long long ans = 0;
    for (int j = 0; j < 32; j++) {
        
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (checkIthBit(A[i], j)) {
                sum++;
            }
        }
        if (sum % 3 != 0) {
            ans = setIthBit(ans, j);
        }
    }
    cout << ans << endl;

    return 0;
}
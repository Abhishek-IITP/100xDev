#include <bits/stdc++.h>

using namespace std;

bool cmp(string& a, string& b) {

    return a+b > b+a;
}


int main() {

    int n;
    cin >> n;

    vector < string > A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end(), cmp);

    if (A[0] == "0") {
        cout << "0";
        return 0;
    }

    for (const string & num: A) {
        cout << num ;
    }

return 0;
}
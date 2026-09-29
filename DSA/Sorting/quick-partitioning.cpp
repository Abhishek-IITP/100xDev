#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, pivot;
    cin >> n >> pivot;

    int A[n];

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int l = 0;
    int r = n - 1;
    int gotPivot = 0;

    for (int i = 0; i < n; i++) {
        if (A[i] == pivot) {
            gotPivot = i;
            swap(A[i], A[r]);
            break;
        }
    }

    l = 0;
    while (l < r) {

        if (A[l] < pivot) {
            l++;
        }
        else {

            swap(A[l], A[r-1]);
            r--;
        }
    }
    swap(A[l], A[n-1]);

    for (int n: A) {
        cout << n << " ";
    }

    return 0;

}
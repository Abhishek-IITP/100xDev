#include <bits/stdc++.h>
using namespace std;

void count_sort(int A[], int n) {

    // Range is -50 to 50
    // Total possible values = 101
    int freq[101] = {0};

    // OFFSET = 50
    // Shift every value by +50 to make it non-negative
    for (int i = 0; i < n; i++) {
        freq[A[i] + 50]++;
    }

    // Print sorted array
    for (int i = 0; i < 101; i++) {

        for (int j = 1; j <= freq[i]; j++) {

            // Remove the offset
            cout << i - 50 << " ";
        }
    }
}

int main() {

    int A[] = {5, -10, 3, -50, 20, 5, -10, 0, 50, -2};

    int n = sizeof(A) / sizeof(A[0]);

    count_sort(A, n);

    return 0;
}
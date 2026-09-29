#include <bits/stdc++.h>
using namespace std;

// Partition around a given pivot value
int partition(int A[], int l, int r, int pivotValue) {

    // Find pivot and move it to the end
    int pivotIndex = l;

    for (int i = l; i <= r; i++) {
        if (A[i] == pivotValue) {
            pivotIndex = i;
            break;
        }
    }

    swap(A[pivotIndex], A[r]);

    int store = l;

    for (int i = l; i < r; i++) {
        if (A[i] < pivotValue) {
            swap(A[i], A[store]);
            store++;
        }
    }

    swap(A[store], A[r]);

    return store;
}


// Find median of a small group
int findMedian(int A[], int l, int r) {

    sort(A + l, A + r + 1);

    int mid = l + (r - l) / 2;

    return A[mid];
}


// Median of Medians
int medianOfMedians(int A[], int l, int r) {

    int n = r - l + 1;

    // If small array, directly find median
    if (n <= 5) {
        return findMedian(A, l, r);
    }

    // Number of groups of 5
    int groups = (n + 4) / 5;

    int* medians = new int[groups];

    int j = 0;

    // Divide into groups of 5
    for (int i = l; i <= r; i += 5) {

        int groupEnd = min(i + 4, r);

        medians[j++] = findMedian(A, i, groupEnd);
    }

    // Find median of medians
    int pivot = medianOfMedians(medians, 0, groups - 1);

    delete[] medians;

    return pivot;
}


void quickSort(int A[], int l, int r) {

    if (l >= r)
        return;

    // Choose pivot using Median of Medians
    int pivotValue = medianOfMedians(A, l, r);

    // Partition around that pivot
    int pivotIndex = partition(A, l, r, pivotValue);

    // Recursively sort both sides
    quickSort(A, l, pivotIndex - 1);
    quickSort(A, pivotIndex + 1, r);
}


int main() {

    int n;
    cin >> n;

    int A[n];

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    quickSort(A, 0, n - 1);

    for (int x : A) {
        cout << x << " ";
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

void merge(int A[], int l, int r) {

    int mid = (l + r) / 2;

    int i = l;
    int j = mid + 1;

    vector < int > temp;

    while (i <= mid && j <= r) {
        if (A[i] <= A[j]) {
            temp.push_back(A[i]);
            i++;
        } else {
            temp.push_back(A[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(A[i]);
        i++;
    }
    while (j <= r) {
        temp.push_back(A[j]);
        j++;
    }

    for (int k = 0; k < temp.size(); k++) {
        A[l + k] = temp[k];
    }
}

void mergeSort(int A[], int l, int r) {

    if (l >= r) return;

    int mid = (l + r) / 2;

    // sort the 1st half
    mergeSort(A, l, mid);

    // sort the 2nd half
    mergeSort(A, mid + 1, r);

    merge(A, l, r);

}

int main() {
    int n = 8;
    int A[8] = {
        3,
        5,
        2,
        8,
        9,
        32,
        6,
        7
    };

    mergeSort(A, 0, n-1);

    for (auto i: A) {
        cout << i << " ";
    }

    return 0;
}
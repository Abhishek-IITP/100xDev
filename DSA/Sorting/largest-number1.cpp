#include <bits/stdc++.h>

using namespace std;

void count_sort(int A[], int n) {
    int freq[10] = {0};

    for (int i = 0; i <n; i++) {
        freq[A[i]]++;
    }
    
    
    // Reverse sorted order
    for (int i = 9; i >= 0; i--) {
        while (freq[i]--) {
            cout << i << " ";
        }
    }
}

int main() {
    
    int A[] = {1,4,2,6,7,8,7};
        
    int n = sizeof(A) / sizeof(A[0]);
    
    count_sort(A,n);
}
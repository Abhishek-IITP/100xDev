#include <bits/stdc++.h>

using namespace std;

int partition(int A[], int start, int end){
    
    int pivot = A[start];
    
    int l = start+1;
    int r = end;
    
    while(l<=r){
        if( A[l]< pivot){
            l++;
        }else {
            swap(A[l], A[r]);
            r--;
        }
    }
    
    swap(A[start], A[r]);
    
    return r;
}

void quickSort(int A[], int l, int r){
    
    if(l>=r) return;
    
    int pivotIndex = partition(A,l,r);
    
    quickSort(A,l, pivotIndex-1);
    quickSort(A, pivotIndex+1,r);
}


int main() {
    int n;
    cin >> n;

    int A[n];

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int l = 0;
    int r = n - 1;
    
    quickSort(A,l,r);
    
    for (int n: A) {
        cout << n << " ";
    }

    return 0;

}
// Use Counting Sort when the values have a small, manageable range. Don't use it when the value range is huge compared to the number of elements.

#include <bits/stdc++.h>

using namespace std;

void count_sort(int A[], int n) {
    int freq[10] = {0};

    for (int i = 0; i <n; i++) {
        freq[A[i]]++;
    }
    
    for(int i =0;i<10;i++){
        
        while(freq[i]--){
            cout<<i<<" ";
        }
    }
}

int main() {
    
    int A[] = {1,4,2,6,7,8,7};
        
    int n = sizeof(A) / sizeof(A[0]);
    
    count_sort(A,n);
}
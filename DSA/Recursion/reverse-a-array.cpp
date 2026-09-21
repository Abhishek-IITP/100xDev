#include <bits/stdc++.h>
using namespace std;

void printArrayInReverse(int A[], int n){
    
    if(n==0){
        return;
    }
    cout<<A[n-1]<<" ";
    printArrayInReverse(A,n-1);
    
}

int main() {
	int n;
	cin>>n;
	
	int A[n];
	
	for(int i =0;i<n;i++){
	    cin>>A[i];
	}
	
	printArrayInReverse(A,n);

}

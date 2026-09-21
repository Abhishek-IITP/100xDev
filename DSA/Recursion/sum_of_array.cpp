#include <bits/stdc++.h>
using namespace std;

int printSumofElementinArray(int A[], int n){
    
    if (n == 1) {
        return A[0];
    }

    int smallAnswer = printSumofElementinArray(A,n-1);
    int ans = smallAnswer + A[n-1];
    return ans;
    
}

int main() {
	int n;
	cin>>n;
	
	int A[n];
	
	for(int i =0;i<n;i++){
	    cin>>A[i];
	}
	
	cout<<printSumofElementinArray(A,n);

}

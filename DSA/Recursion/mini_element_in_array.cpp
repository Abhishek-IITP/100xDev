#include <bits/stdc++.h>
using namespace std;

int printMiniElementinArray(int A[], int n){
    
    if (n == 1) {
        return A[0];
    }

    int smallAnswer = printMiniElementinArray(A,n-1);
    int ans = min(smallAnswer,A[n-1]);
    return ans;
    
}

int main() {
	int n;
	cin>>n;
	
	int A[n];
	
	for(int i =0;i<n;i++){
	    cin>>A[i];
	}
	
	cout<<printMiniElementinArray(A,n);

}

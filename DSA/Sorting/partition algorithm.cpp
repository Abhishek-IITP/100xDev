#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,x;
	cin>>n>>x;
	    
	int A[n];
	for(int i =0;i<n;i++){
	    cin>>A[i];
	}
	
	int l = 0;
	int r = n-1;
	
	while(l<=r){
	    if( A[l] <x){
	        l++;
	    }
	    else{
	        swap(A[l], A[r]);
            
            r--;
	    }
	}
	
	for(int n: A){
	    cout<<n<<" ";
	}
	
	return 0;

}

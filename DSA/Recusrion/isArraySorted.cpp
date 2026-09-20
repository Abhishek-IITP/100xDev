#include <bits/stdc++.h>
using namespace std;

bool isArraySorted(int A[], int n){
    
    if(n <= 1) {
    return true;
}

    bool smallAns = isArraySorted(A,n-1);
    
    if(!smallAns){
        return false;
    }
    
    return A[n-1]>= A[n-2];
}

int main() {
	int n;
	cin>>n;
	
	int A[n];
	
	for(int i =0;i<n;i++){
	    cin>>A[i];
	}
	
	
	 if(isArraySorted(A,n)) cout<<"YES";
	 else cout<<"NO"<<endl;

return 0;
    
}

#include <bits/stdc++.h>
using namespace std;

int lastOccuranceofX(int A[], int n, int target){
    
    if(n==0) return -1;
    
    
    if(A[n-1] == target) return n-1;
    
    int smallAns = lastOccuranceofX(A,n-1,target);
    return smallAns;
}

int main() {
	int n,x;
	cin>>n>>x;
	
	int A[n];
	
	for(int i =0;i<n;i++){
	    cin>>A[i];
	}
	
	int ans = lastOccuranceofX(A,n,x);
	cout<<"Last Occurance of "<< x <<" "<<"is at"<<" "<<ans;
	
	return 0;

}

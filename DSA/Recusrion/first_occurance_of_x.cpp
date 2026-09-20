#include <bits/stdc++.h>
using namespace std;

int firstOccuranceofX(int A[], int n, int target){
    
    if(n==0) return -1;
    
    int smallAns = firstOccuranceofX(A,n-1,target);
    
    if(smallAns != -1) return smallAns;
    
    if(A[n-1] == target) return n-1;
    
    return -1;
}

int main() {
	int n,x;
	cin>>n>>x;
	
	int A[n];
	
	for(int i =0;i<n;i++){
	    cin>>A[i];
	}
	
	int ans = firstOccuranceofX(A,n,x);
	cout<<"First Occurance of "<< x <<" "<<"is at"<<" "<<ans;
	
	return 0;

}

#include <bits/stdc++.h>
using namespace std;

void allOccuranceofX(int A[], int n, long long target){
    
    if(n==0) return ;
    
    allOccuranceofX(A,n-1,target);
    
    if(A[n-1] == target) cout<< n<<" ";
    
}

int main() {
	int n;
	cin>>n;
	
	int A[n];
	
	for(int i =0;i<n;i++){
	    cin>>A[i];
	}
	
	long long x;
	cin>>x;
	
	 allOccuranceofX(A,n,x);
	return 0;

}

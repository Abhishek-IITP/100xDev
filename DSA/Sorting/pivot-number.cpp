#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,x;
	cin>>n>>x;
	    
	int A[n];
	for(int i =0;i<n;i++){
	    cin>>A[i];
	}
	
	int size = 0;
	int count= 0;
	
	for(int i =0;i<n;i++){
	    if(A[i] > x){
	        count++;
	    }
	    size++;
	}
	
	cout<< size - 1 - count <<endl;
// 	for(int n: A){
// 	    cout<<n<<" ";
// 	}
	
	return 0;

}

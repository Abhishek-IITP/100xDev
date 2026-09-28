#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
    
    if(abs(a)%10 != abs(b)%10){
        return abs(a)%10 < abs(b)%10 // last digit same ni h toh last digit ko compare kr do 
    }
    return a<b; // aagar last digit same h toh number ko compare kr do 
}

int main() {
	
	int n;
	cin>>n;
	
	int A[n];
	
	for(int i= 0;i<n;i++){
	    cin>>A[i];
	}
	
	sort(A, A+n, cmp);
	
	for(int i =0;i<n;i++){
	    cout<<A[i]<<" ";
	}

}

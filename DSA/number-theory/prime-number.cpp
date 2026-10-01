#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n;
	cin>>n;
	vector<int>factor(n+1) ;
	
	if(n%i == 0 ) return false; 
    
    for(int i =1;i<n;i++){
        for(int j = i;j<n;j+=i){
            factor[j]++;
        }
    }
    
    for(int i =0;i<n;i++){
        if(factor[i] == 2){
            cout<<i<<" "<<"Is a prime number "<<endl;
        }
    }
    
    return 0;
}


// also 

bool isPrime(int n) {
    if (n < 2) return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}
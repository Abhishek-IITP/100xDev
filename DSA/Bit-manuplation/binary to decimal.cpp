#include <bits/stdc++.h>
using namespace std;

int main() {
	string k;
	cin>>k;
	
	long long ans = 0;
    long long power = 1;
	 for (int i = k.size() - 1; i >= 0; i--){
	    if(k[i] =='1'){
	        ans +=power;
	    }
	    power*=2;
	}
	cout<<ans;
	
	return 0;

}

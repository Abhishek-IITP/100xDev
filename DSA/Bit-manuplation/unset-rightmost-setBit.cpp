#include <bits/stdc++.h>
using namespace std;

bool checkithBit(int n,int i){
    int mask = 1<<i;
    
    if((n& mask) == 0){
        return 0;
    }else return 1;
}

int unsetithBit(int n,int i){
    int mask = ~(1<<i);
    return n&mask; 
}

int main() {
	int n,ans;
	cin>>n;
	
	for(int i =0;i<31;i++){
	    if(checkithBit(n,i) == 1){
	        ans = unsetithBit(n,i);
	        break;
	    }
	}
	cout << ans << endl;
	

}

//without loop 

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	
	
	cout<< (n&(n-1))<<endl;
	
	return 0;

}

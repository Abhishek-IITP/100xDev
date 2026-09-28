#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b){
    
    int lengthA = a.size();
    int lengthB = b.size();
    
    if(lengthB != lengthA) return lengthA<lengthB;
    
    return a<b;
    
    
}

int main() {
	
	int n;
	cin>>n;
	
	string A[n];
	
	for(int i= 0;i<n;i++){
	    cin>>A[i];
	}
	
	sort(A, A+n, cmp);
	
	for(int i =0;i<n;i++){
	    cout<<A[i]<<endl;
	}

}

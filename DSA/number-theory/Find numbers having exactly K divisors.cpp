#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    
    vector<int>vec(n+1);
    
    for( int i = 1;i<=n;i++){
        for( int j = i;j<=n;j+=i){
            vec[j]++;
        }
    }
    
    for(int i = 0;i<=n;i++){
        if(vec[i] == k){
            cout<<i<< " ";
        }
    }
return 0;
}

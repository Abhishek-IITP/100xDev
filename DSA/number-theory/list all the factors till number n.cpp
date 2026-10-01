#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	
	vector<int>factors[n+1] ;
    
    for(int i =1; i<=n;i++){
        for(int j =i;j<=n;j+=i){
            factors[j].push_back(i);
        }
    }
    
       for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int x : factors[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
    
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n;
	cin>>n;
	
	vector<int> vec[n+1];

    for( int i = 1;i<=n;i++){
        for(int j = i;j<=n;j+=i){
            vec[j].push_back(i);
        }
    }
    
    int k;
    cin>>k;
    
    
    for(int i =1;i<=n;i++){
        cout<<i<<": ";
        
        for(int x: vec[i]){
            cout<<x<< " ";
        }
    cout<<endl;
    }
    
        cout<< "Factors of K: ";
    for(int x: vec[k]){
    
    cout<<x<<" ";
        
    }
    
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

void printPath(vector<int>& path){
    for(auto& num: path){
        cout<<num<<" ";
    }
    cout<<endl;
}

void fn(int curr,int n,int k,vector<int>& path){
    
    if(curr == n){
        printPath(path);
        return;
    }
    
    if(curr>n) return;
    
    for(int i = 1;i<=k;i++){
        
        path.push_back(i);
        fn(curr + i,n,k,path);
        path.pop_back();
    }
}

int main() {
    
    int n,k;
    
    cin>>n>>k;
    
    
    //n = kha tk jna h , k = kitne possibility h jump krne ka, if k = 3 , then every step pe we can jump either 1,2 or 3.
	vector<int>path;
	
	fn(0,n,k,path);
	

}

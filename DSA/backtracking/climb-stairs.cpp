#include <bits/stdc++.h>
using namespace std;

void printPath(vector<int>& path){
    for(auto& num: path){
        cout<<num<<" ";
    }
    cout<<endl;
}

void fn(int curr,int n,vector<int>& path){
    
    if(curr == n){
        printPath(path);
        return;
    }
    
    if(curr>n) return;
    
    //jump of 1 
    path.push_back(1);
    fn(curr+1, n, path);
    path.pop_back();
    
    //jump of 2
    path.push_back(2);
    fn(curr+2, n, path);
    path.pop_back();
}

int main() {
	vector<int>path;
	
	fn(0,5,path);
	

}

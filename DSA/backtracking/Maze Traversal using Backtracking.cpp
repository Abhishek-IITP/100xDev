#include <bits/stdc++.h>
using namespace std;

void printPath(vector<string>& path){
    for(auto& num: path){
        cout<<num<<" ";
    }    
    cout<<endl;
}

void fn(int i, int j, int n,int m,vector<string>& path,vector<vector<bool>>& visited){
    
    if(i<0 || i>=n || j<0 || j>=m){
        return;        
    }
    
    if(visited[i][j]){
        return;
    }
    
    if(i ==n-1 && j == m-1){
        printPath(path);
        return;
    }
        
    
    
    visited[i][j]= true;
    //right
    path.push_back("r");
    fn(i,j+1,n,m,path,visited);
    path.pop_back();
    
    //left
    path.push_back("l");
    fn(i,j-1,n,m,path,visited);
    path.pop_back();
    
    //up
    path.push_back("u");
    fn(i-1,j,n,m,path,visited);
    path.pop_back();
    
    //Down
    path.push_back("d");
    fn(i+1,j,n,m,path,visited);
    path.pop_back();
    
    visited[i][j] = false;
}

int main() {
	
	int n,m;
    
    cin>>n>>m;
    
    vector<string>path;
    
    vector<vector<bool>>visited(n, vector<bool> (m, false));
    
    fn(0,0,n,m,path,visited);
    
    
    return 0;

}

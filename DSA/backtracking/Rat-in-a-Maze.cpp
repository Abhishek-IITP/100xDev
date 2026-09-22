#include <bits/stdc++.h>
using namespace std;

void printPath(vector<string>& path){
    for(auto& num: path){
        cout<<num<<" ";
    }
    cout<<endl;
}

void fn(int i,int j,int n,int m,vector<string>& path){
    
    //reached the fianl destination
    if(i == n-1 && j == m-1){
        printPath(path);
        return;
    }
    
    //outside the grid
    if(i>n || j>m) return;
        
        //right
        path.push_back("r");
        fn(i,j + 1,n,m,path);
        path.pop_back();

        //down
        path.push_back("d");
        fn(i+1,j ,n,m,path);
        path.pop_back();
}

int main() {
    
    int n,m;
    
    cin>>n>>m;
    
	vector<string>path;
	
	fn(0,0,n,m,path);
	

}

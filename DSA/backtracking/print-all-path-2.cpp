#include <bits/stdc++.h>

using namespace std;

void fn(int i,int j, int n, int m,vector < vector < int >>& path, string& ans){
    
    if(i <0 || i>=n || j<0 || j>=m) return;
    
    if(path[i][j] == 1){
        return;
    }
    if(i == n-1 && j == m-1){
        cout<<ans<<endl;
        return;
    }
    
    
    //right
    
    ans.push_back('R');
    fn(i,j+1,n,m,path,ans);
    ans.pop_back();
    
    //down
    
    ans.push_back('D');
    fn(i+1,j,n,m,path,ans);
    ans.pop_back();
}

int main() {
    int n, m;
    cin >> n >> m;

    vector < vector < int >> path(n, vector < int > (m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> path[i][j];
        }
    }
    
    string ans;
    
    fn(0,0,n,m,path,ans);
    
    return 0;
}
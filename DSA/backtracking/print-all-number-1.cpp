#include <bits/stdc++.h>

using namespace std;

void printPath(vector < string > & path) {

    for (auto& ch: path) {
        cout << ch << " ";
    }
    cout << endl;
}


void fn(int i, int j, int n ,int m, string& path){
    
    if( i ==n-1 && j == m-1 ){
        cout<< path<<endl;
        return;
    }
    if(i<0 || i>=n || j<0 || j>=m) return;
        
    //go right
    path.push_back('R');
    fn(i,j+1,n,m,path);
    path.pop_back();
    
    //go down
    path.push_back('D');
    fn(i+1,j,n,m,path);
    path.pop_back();
    
}

int main() {

    int n,m;
    cin >> n>>m;

    string  path;

    fn(0,0,n,m, path);

    return 0;
}
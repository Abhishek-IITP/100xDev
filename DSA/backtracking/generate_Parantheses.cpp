#include <bits/stdc++.h>
using namespace std;

void printString(const string& s) {
    cout << s << endl;
}

void fn(int open, int close, int n, string path){
    
    if(open == n && close == n){
        printString(path);
        return;
    }
    
    //open bracket 
    if(open<n){
        path.push_back('(');
        fn(open+1,close,n,path);
        path.pop_back();
    }
    
    //close bracket
    
    if(open>close){
        path.push_back(')');
        fn(open,close+1,n,path);
        path.pop_back();
    }
}
int main() {
    int n;
    cin>>n;
    
    string path;
    
    fn(0,0,n, path);
}

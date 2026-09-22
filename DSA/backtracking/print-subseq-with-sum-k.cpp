#include <bits/stdc++.h>

using namespace std;

void printPath(const vector <int> & path) {
    for (auto& num: path) {
        cout << num << " ";
    }
    cout << endl;
}

void fn(int i, vector<int>& A,vector<int>& path,int sum,int k) {

    if(i == A.size()) {
        if(sum == k){
        printPath(path);
        }
        return;
    }

    //take
    path.push_back(A[i]);
    fn(i+1,A,path,sum+A[i],k);
    path.pop_back();

    //not-take
    fn(i+1,A,path,sum,k);


}

int main() {

    int n,k;

    cin >> n>>k;
    int sum =0;

    vector < int > A(n);
    vector < int > path;

    for(int i =0;i<n;i++){
        cin>>A[i];
    }

    fn(0,A,path,sum,k);


}
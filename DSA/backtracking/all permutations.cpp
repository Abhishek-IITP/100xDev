#include <bits/stdc++.h>
using namespace std;

void printPath(vector<int>& path){
    
    for(auto& num: path){
        cout<<num<<" ";
    }
    cout<<endl;
}

void fn(int n, int A[], vector<bool>& used,
	vector<int>& path
	){
	    if (path.size() == n){
	        printPath(path);
	        return;
	    }
	    
	    for(int i =0;i<n;i++){
	        if (!used[i]){
	            //choose 
	            
	            path.push_back(A[i]);
	            used[i]= true;
	            
	            //explore
	            fn(n,A,used,path);
	               
	            // Undo choices
	            used[i]= false;
	            path.pop_back();
	        }
	    }
	}

int main() {
	
	int n;
	cin>>n;
	
	int A[n];
	
	for(int i =0;i<n;i++){
	    cin>>A[i];
	}
	
	vector<bool>used(n,false);
	vector<int>path;
	
	fn(n,A,used, path);

}

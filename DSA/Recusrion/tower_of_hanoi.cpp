#include <bits/stdc++.h>
using namespace std;

void fn(int n,char src,char aux,char dest){
    
    if(n==0) return;
    
    fn(n-1, src,dest,aux); //move from src to aux
    
    cout<<"Move From " <<src<<" to "<<dest<<endl; //move the largest disk from src to dest
    
    fn(n-1,aux,src,dest); //move from aux to dest 
    
}

int main() {
	int n;
	cin>>n;
	 
	 fn(n,'A','B','C');
	return 0;

}

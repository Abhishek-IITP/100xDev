// Custom Comparator: Sort by Magnitude, Then by Value Descending

#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
    
    int magnitudeA = abs(a);
    int magnitudeB = abs(b);
    
    if(magnitudeA != magnitudeB){
        return magnitudeA<magnitudeB;
    }
    
    return a>b;
    
    
}

int main() {
	
	int n;
	cin>>n;
	
	int A[n];
	
	for(int i= 0;i<n;i++){
	    cin>>A[i];
	}
	
	sort(A, A+n, cmp);
	
	for(int i =0;i<n;i++){
	    cout<<A[i]<<" ";
	}

}

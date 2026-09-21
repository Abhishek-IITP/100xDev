#include<bits/stdc++.h>
using namespace std;


int f(int n){

     if(n ==0){
          return 0;
     }
     int ans = n;
     ans+= f(n-1);
     return ans;

}
int main(){
     int n;
     cin>>n;
     
     cout<<f(n);
}
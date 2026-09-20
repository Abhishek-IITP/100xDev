#include<bits/stdc++.h>
using namespace std;


int f(int a,int b){

     int smallPart = f(a,b-1);
     int ans = a * smallPart;

     return ans;

}
int main(){
     int a;
     int b;
     cin>>a>>b;

     cout<<f(a,b);
}
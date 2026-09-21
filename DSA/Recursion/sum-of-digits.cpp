#include<bits/stdc++.h>
using namespace std;


int f(int a){


     int sum =0;
     sum += f(a%10);
     f(a/10);

     return ans;

}
int main(){
     int a;

     cout<<f(a);
}
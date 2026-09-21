// #include<bits/stdc++.h>
// using namespace std;


// int f(int n){

//      if(n ==0){
//           return 1;
//      }
//      int ans = n;
//      ans*= f(n-1);
//      return ans;

// }
// int main(){
//      int n;
//      cin>>n;
     
//      cout<<f(n);
// }

#include <bits/stdc++.h>
using namespace std;

void f(int n,int ans){
    if(n == 0) {
        cout<<ans;
        return;
    };

    ans*=n;
    f(n-1,ans);
    
}

int main() {
    int x;
    cin >> x;
    
     if(x == 0) {
        cout<<1;
    } else{
        
    f(x,1);
    }

}

#include <bits/stdc++.h>
using namespace std;

long long fun(long long n){
    if(n == 0) {
        return 1;
    };
    long long smallanswer =fun(n-1);
    long long  ans = smallanswer*n;
    return ans;
    
}
int main() {
    long long x;
    cin>>x;
    cout<<fun(x);
    return 0;
}

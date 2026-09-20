// #include <bits/stdc++.h>
// using namespace std;



// void f(int n){
//     int k =n;
    
//     if(k ==0) return;
    
//     cout<<k<<endl;
//     f(k-1);
// }
// void a(int n){
//     int k =n;
//     if(k ==1) return;
//     a(k-1);
//     cout<<k<<endl;
     
// }
// int main() {
// 	int x;
// 	cin>>x;
	
// 	f(x);
// 	a(x);
// }


#include <bits/stdc++.h>
using namespace std;

void f(int n){

    if(n == 1) {
        cout<<1<<endl;
        return;
        
    };

    cout << n << endl;
    f(n-1);
    cout << n << endl;
    
}

int main() {
    int x;
    cin >> x;

    f(x);
}

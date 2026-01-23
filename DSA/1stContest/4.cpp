#include <iostream>
using namespace std;

int main() {
    int num;
    cin>>num;
    if(num%100==0){
        if(num%400 ==0){
            cout<<"Yes";
        }
        else cout<<"No";
    }
    else{
        if(num%4==0){
            cout<<"Yes";
        }
        else cout<<"No";
    }
    return 0;
}

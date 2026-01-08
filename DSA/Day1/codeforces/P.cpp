#include <bits/stdc++.h>
using namespace std;

int main() {
    int Marks;
    cin>>Marks;
    
    if(Marks>90 && Marks<=100){
        cout<<"Excellent"<<endl;
    }
    else if(Marks>80 && Marks<=90){
        cout<<"Good";
    }
    else if(Marks>70 && Marks<=80){
        cout<<"Fair";
    }
    else if(Marks>60 && Marks<=70){
        cout<<"Meets Expectations";
    }
    else{
        cout<<"Below Par"<<endl;
    }
}

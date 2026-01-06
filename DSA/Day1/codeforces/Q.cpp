#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    int y;
    cin>>x>>y;
    
    if(x == 0 && y == 0) cout<<"Origin";
    if(x==0 && y!=0) cout<<"Y axis";
    if(x!=0 && y==0) cout<<"X axis";
    if(x>0 && y>0) cout<<"1st Quadrant";
    if(x<0 && y>0) cout<<"2nd Quadrant";
    if(x<0 && y<0) cout<<"3rd Quadrant";
    if(x>0 && y<0) cout<<"4th Quadrant";
    
}

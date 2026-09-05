#include <bits/stdc++.h>
using namespace std;

int checkithBit(int n,int i){
    int mask = 1<<i;
    
    if((n&mask) == 0){
        return 0;
    }else return 1;
}
int main() {
	int n;
    cin>>n;
    
    if(checkithBit(n,0) == 0){
        cout<<"Even"<<endl;
    }else cout<<"Odd"<<endl;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n & 1)
        cout << "Odd" << endl;
    else
        cout << "Even" << endl;

    return 0;
}
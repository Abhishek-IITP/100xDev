#include <bits/stdc++.h>

using namespace std;

int main() {
    int k ;
    cin>>k;
    
    if (k == 0) {
        cout << 0;
        return 0;
    }
    
    string s;
    
    while(k>0){
        s += (k % 2) + '0';
        k/=2;
    }
    reverse(s.begin(), s.end());

    cout << s;
    
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    int k ;
    cin>>k;
    
    if (k == 0) {
        cout << 0;
        return 0;
    }
    
    string s;
    
    while (k > 0) {
        s += (k & 1) + '0';
        k >>= 1;
    }
    reverse(s.begin(), s.end());

    cout << s;
    
    return 0;
}
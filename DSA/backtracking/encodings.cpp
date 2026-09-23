#include <bits/stdc++.h>

using namespace std;


void fn(int curr, string n, string& path) {
    
    if(curr == n.size()){
        cout<<path<<endl;
        return;
    }

    int digit = n[curr] - '0';

    if (digit >= 1 && digit <= 9) {
        path.push_back('A' + digit - 1);
        fn(curr + 1, n, path);
        path.pop_back();
    }

    if (curr + 1 < n.size()) {

        int num = (n[curr] - '0') * 10 + (n[curr + 1] - '0');
        if (num >= 10 && num <= 26) {

            path.push_back('A' + num - 1);
            fn(curr + 2, n, path);
            path.pop_back();
        }
    }


}

int main() {

    string n;

    cin >> n;
    string path;

    fn(0, n, path);



}
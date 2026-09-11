#include <bits/stdc++.h>

using namespace std;

int main() {
    int curr = 1;
    int n;
    cin >> n;
    
    while (curr <= n) {
        curr *= 2;
    }
    
    curr/=2;
    
    while(n>0) {
        if (curr <= n) {
            cout << curr << " ";
            n -= curr;
        }
        curr/=2;
    }
    return 0;

}



#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a;

    int curr = 1;

    while (curr <= n) {
        a.push_back(curr);
        curr *= 2;
    }

    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] <= n) {
            cout << a[i] << " ";
            n -= a[i];
        }
    }

    return 0;
}
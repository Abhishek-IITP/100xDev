#include <bits/stdc++.h>

using namespace std;

int main() {
    int curr = 1;
    int n;
    cin >> n;
    while (curr <= n) {
        cout << curr << " ";
        curr *= 2;
    }

    return 0;

}
#include <bits/stdc++.h>

using namespace std;

int main() {
    long long a;
    cin >> a;

    long long curr = 1;

    while (curr <= a) {
        cout << curr << " ";
        curr <<= 1;
    }

    return 0;
}
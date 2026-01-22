#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long x;
    int count = 0;

    while (n--) {
        cin >> x;
        if ((x != 0 && 18 % x == 0) || x % 45 == 0)
            count++;
    }

    cout << count;
    return 0;
}

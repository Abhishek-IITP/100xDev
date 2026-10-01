#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";

            if (i != n / i)
                cout << n / i << " ";
        }
    }
    return 0;
}

// sum of all the divisors


#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    int sum =0;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            sum+=i;

            if (i != n / i)
                sum+=n / i;
        }
    }
    cout << sum;
    return 0;
}

//  Find proper divisior of a number

#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";

            if (i != n / i){
                if(n/i != n){
                cout << n / i << " ";
                }
            }
        }
    }
    return 0;
}

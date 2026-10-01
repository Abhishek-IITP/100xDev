#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    int count = 0;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count++;

            if (i != n / i)
                count++;
        }

    }
    cout << count;
    return 0;
}

// Sum of divisors for every number from 1 to N

#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    
    vector<int>sum(n+1);
    

    for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
        sum[j] += i;
    }
}
    
    for (int i = 1; i <= n; i++) {
        cout << i << ": " << sum[i] << endl;
    }

    
    return 0;
}


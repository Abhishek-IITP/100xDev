#include <bits/stdc++.h>
using namespace std;

int f(int A[], int n)
{
    if(n == 1) return A[0];

    int smallAns = f(A, n - 1);
    int ans = min(smallAns, A[n - 1]);

    return ans;
}

int main() {

    int A[] = {10, 20, 30, 40, 50};

    cout << f(A, 5);

    return 0;
}
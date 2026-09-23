#include <bits/stdc++.h>
using namespace std;

void printPath(vector<int>& path) {
    for(int x : path) {
        cout << x;
    }
    cout << endl;
}

void fn(int curr, int sum,
        vector<int>& A,
        int target,
        vector<int>& path) {

    // Found target
    if(sum == target) {
        printPath(path);
        return;
    }

    // No more elements
    if(curr == A.size() || sum>target) {
        return;
    }

    // TAKE
    // curr stays same -> element can be reused
    path.push_back(A[curr]);

    fn(curr, sum + A[curr], A, target, path);

    path.pop_back();

    // NOT TAKE
    // move to next element
    fn(curr + 1, sum, A, target, path);
}

int main() {

    int n, target;
    cin >> n >> target;

    vector<int> A(n);

    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<int> path;

    fn(0, 0, A, target, path);
}
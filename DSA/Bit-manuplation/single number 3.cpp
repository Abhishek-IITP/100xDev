#include <bits/stdc++.h>

using namespace std;

int checkBit(long long num, int i) {
    long long mask = 1LL << i;
    return (num & mask) ? 1 : 0;
}

int main() {
    int n;
    cin >> n;

    vector <long long> nums(n);
    long long xor_arr = 0;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        xor_arr ^= nums[i];
    }

    //figure out any postion in which they both  differ 
    // => postion of any set bit in xor_arr

    int pos = -1;
    for (int i = 0; i < 32; i++) {
        if (checkBit(xor_arr, i) == 1) {
            pos = i;
            break;
        }
    }
    // xor of groups seperately

    long long group1 = 0;
    long long group2 = 0;

    for (long long x: nums) {
        if (checkBit(x, pos)) {
            group1 ^= x;
        } else group2 ^= x;
    }

    cout << group1 << " " << group2 << endl;

    return 0;
}
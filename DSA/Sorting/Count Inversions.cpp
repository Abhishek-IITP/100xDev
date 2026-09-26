#include <bits/stdc++.h>

using namespace std;

int merge(int A[], int l, int r) {

    int mid = (l + r) / 2;

    int i = l;
    int j = mid + 1;
    int ans =0;
    vector < int > temp;

    while (i <= mid && j <= r) {
        if (A[i] <= A[j]) {
            temp.push_back(A[i]);
            i++;
        } else {
            temp.push_back(A[j]);
            //to count rem inversion from 2nd half
            ans+=  mid -i + 1;
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(A[i]);
        i++;
    }
    while (j <= r) {
        temp.push_back(A[j]);
        j++;
    }

    for (int k = 0; k < temp.size(); k++) {
        A[l + k] = temp[k];
    }
    
    return ans;
}

int fn(int A[], int l, int r) {

    if (l >= r) return 0;

    int mid = (l + r) / 2;

    // sort the 1st half and bring back to the inversion
    int ans1 = fn(A, l, mid);

    // sort the 2nd half and bring back to the inversion
    
    int ans2= fn(A, mid + 1, r);
    
    //merge these 2 sorted array amd count the rem inversion
    
    int ans3 =merge(A, l, r);

    return ans1+ans2+ans3;
}

int main() {
    int n = 9;
    int A[9] = {
        10,
        5,
        3,
        2,
        1,
        6,
        3,
        7,
        8,
    };

    cout<<fn(A, 0, n-1)<<endl;



    return 0;
}
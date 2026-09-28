#include <bits/stdc++.h>

using namespace std;


struct Student {
    string name;
    int marks;
};

bool cmp(Student a, Student b) {

    if (a.marks != b.marks) {
        return a.marks > b.marks;
    }
    return a.name.size() < b.name.size(); // if marks were same and you need to return on the basis of size
    return a.name < b.name; // if marks were same and you need to return on the basis of lexicographical order


}

int main() {

    int n;
    cin >> n;

    Student A[n];

    for (int i = 0; i < n; i++) {
        cin >> A[i].name >> A[i].marks;
    }

    sort(A, A + n, cmp);

    for (int i = 0; i < n; i++) {
        cout << A[i].name << " " << A[i].marks << endl;
    }

}
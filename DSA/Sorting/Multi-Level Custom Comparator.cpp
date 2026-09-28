#include <bits/stdc++.h>

using namespace std;


struct Student {
    string name;
    int totalMarks;
    int physicsMarks;
    int chemistryMarks;
    int mathMarks;
};

bool cmp(Student a, Student b) {

    if (a.totalMarks != b.totalMarks) {
        return a.totalMarks > b.totalMarks;
    }
    if(a.mathMarks != b.mathMarks) return a.mathMarks > b.mathMarks;

    if(a.physicsMarks != b.physicsMarks) return a.physicsMarks > b.physicsMarks;
    
    return a.name < b.name;

}

int main() {

    int n;
    cin >> n;

    Student A[n];

    for (int i = 0; i < n; i++) {
        cin >> A[i].name >> A[i].totalMarks >> A[i].physicsMarks>>A[i].chemistryMarks>> A[i].mathMarks;
    }

    sort(A, A + n, cmp);

    for (int i = 0; i < n; i++) {
        cout <<A[i].name << " " << A[i].totalMarks << " " << A[i].physicsMarks << " " << A[i].chemistryMarks << " " << A[i].mathMarks << endl;
    }

}
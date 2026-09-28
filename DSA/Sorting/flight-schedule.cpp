include <bits/stdc++.h>
using namespace std;
 
struct Flight {
    int flightNumber;
    int departureTime;
    string destination;
};
 
bool cmp(const Flight& a, const Flight& b) {
 
    // 1. Earlier departure time first
    if (a.departureTime != b.departureTime) {
        return a.departureTime < b.departureTime;
    }
 
    // 2. If departure time is same,
    //    smaller flight number first
    return a.flightNumber < b.flightNumber;
}
 
int main() {
 
    int n;
    cin >> n;
 
    vector<Flight> A(n);
 
    for (int i = 0; i < n; i++) {
        cin >> A[i].flightNumber
            >> A[i].departureTime
            >> A[i].destination;
    }
 
    sort(A.begin(), A.end(), cmp);
 
    for (const Flight& f : A) {
        cout << f.flightNumber << " "
             << f.departureTime << " "
             << f.destination << '\n';
    }
 
    return 0;
}

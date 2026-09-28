#include <bits/stdc++.h>
using namespace std;

struct Plane {
    int x;
    int y;
};

long long refX, refY;

bool cmp(const Plane& a, const Plane& b) {

    long long dx1 = a.x - refX;
    long long dy1 = a.y - refY;

    long long dx2 = b.x - refX;
    long long dy2 = b.y - refY;

    long long distA = dx1 * dx1 + dy1 * dy1;
    long long distB = dx2 * dx2 + dy2 * dy2;

    // 1. Smaller distance first
    if (distA != distB) {
        return distA < distB;
    }

    // 2. Same distance → smaller x first
    if (a.x != b.x) {
        return a.x < b.x;
    }

    // 3. Same distance + same x → smaller y first
    return a.y < b.y;
}

int main() {

    int n;
    cin >> n >> refX >> refY;

    vector<Plane> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i].x >> A[i].y;
    }

    sort(A.begin(), A.end(), cmp);

    for (const Plane& p : A) {
        cout << p.x << " " << p.y << '\n';
    }

    return 0;
}
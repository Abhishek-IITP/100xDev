#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = N; i >= 1; i--) {
        for (int s = 0; s < N - i; s++)
            cout << " ";
        for (int d = 1; d <= i; d++) {
            cout << ".";
            if (d != i) cout << " ";
        }
        cout << endl;
    }

    for (int i = 2; i <= N; i++) {
        for (int s = 0; s < N - i; s++)
            cout << " ";
        for (int d = 1; d <= i; d++) {
            cout << ".";
            if (d != i) cout << " ";
        }
        cout << endl;
    }

    return 0;
}

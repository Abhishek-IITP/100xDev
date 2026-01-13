#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int s = 1; s < i; s++) {
            cout << " ";
        }

        cout << ">";
        if (i > 1) {
            for (int sp = 1; sp <= 2 * (i - 2) + 1; sp++) {
                cout << " ";
            }
            cout << ">";
        }

        cout << endl;
    }
    for (int i = N - 1; i >= 1; i--) {

        for (int s = 1; s < i; s++) {
            cout << " ";
        }

        cout << ">";

        if (i > 1) {
            for (int sp = 1; sp <= 2 * (i - 2) + 1; sp++) {
                cout << " ";
            }
            cout << ">";
        }

        cout <<endl;
    }

    return 0;
}

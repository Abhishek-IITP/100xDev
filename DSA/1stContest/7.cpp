#include <iostream>
using namespace std;

int main() {
    long long N;
    cin>>N;
    int count =0;
    if(N == 0) {
    cout<<1;
    return 0;    
    }

    while (N > 0) {
        if (N % 10 == 0)
            count++;
        N /= 10;
    }

    cout << count;
    return 0;
}

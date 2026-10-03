#include <bits/stdc++.h>
using namespace std;

class Vector {
    int *arr;
    int sz;

public:
    Vector(int size) {
        arr = new int[size];
        sz = size;
    }

    void push_back(int x) {
        int *newArr = new int[sz + 1];

        for (int i = 0; i < sz; i++) {
            newArr[i] = arr[i];
        }

        newArr[sz] = x;
        sz++;

        delete[] arr;
        arr = newArr;
    }
    
      void print() {
        for (int i = 0; i < sz; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
	
	Vector arr(0);
	
	arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    
	arr.print();
	
	arr.push_back(99);
	
	arr.print();

}

#include <bits/stdc++.h>

using namespace std;

void count_sort(string s, int n) {
    int freq[26] = {0};

    for (int i = 0; i <n; i++) {
        int num = s[i] -'a';
        freq[num]++;
    }
    

    for (int i = 0; i <26; i++) {
        while (freq[i]--) {
            cout << char(i + 'a');
        }
    }
}

int main() {
    
    string s = "abcabdgjisdnjrfboq";
        
    int n = s.size();
    
    count_sort(s,n);
}
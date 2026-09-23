#include <bits/stdc++.h>
using namespace std;

map<char, string> keypad = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};

void fn(string& s, int n, string& path) {

    if(n == s.size()) {
        cout << path << endl;
        return;
    }

    char digit = s[n];
    string choices = keypad[digit];

    for(char ch : choices) {
        path.push_back(ch);

        fn(s, n + 1, path);

        path.pop_back();
    }
}

int main() {
    string s;
    cin >> s;

    string path;
    fn(s, 0, path);
}
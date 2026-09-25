class Solution {
public:
    map<char, string> keypad = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                {'8', "tuv"}, {'9', "wxyz"}};

    void fn(int i , string& s, string& path ,vector<string>& ans){

        if(i == s.size()){
            ans.push_back(path);
            return;
        }

        int digit = s[i];

        string choices = keypad[digit];

        for(char ch: choices){

            path.push_back(ch);
            fn(i+1,s,path,ans);
            path.pop_back();
        }
        

    }

    vector<string> letterCombinations(string digits) {

        vector<string> ans;
        if (digits.empty()) {
            return ans;
        }

        string path;

        fn(0, digits,path,ans);

        return ans;
    };
};
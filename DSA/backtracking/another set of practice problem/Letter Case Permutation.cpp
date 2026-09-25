class Solution {
public:
    void fn(int i , string& s, string& path,vector<string>& ans){

        if(i== s.size()){
            ans.push_back(path);
            return;
        }
        if(i>s.size()) return;

        //digit
        if(isdigit(s[i])){
            path.push_back(s[i]);
            fn(i+1,s,path,ans);
            path.pop_back();
        
        }else{ //letter

            //lowercase
            path.push_back(tolower(s[i]));
            fn(i+1,s,path,ans);
            path.pop_back();
            
            //Uppercase
            path.push_back(toupper(s[i]));
            fn(i+1,s,path,ans);
            path.pop_back();
        }
    }
    vector<string> letterCasePermutation(string s) {
        
        string path;
        vector<string>ans;

        fn(0,s,path,ans);
        return ans;
    }
};
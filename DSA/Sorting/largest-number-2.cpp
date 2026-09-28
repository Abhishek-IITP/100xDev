class Solution {
public:

    static bool cmp(const string& a, const string& b){
        return a+b> b+a;
    }

    string largestNumber(vector<int>& nums) {
        
        vector<string>ans;

        for(int num: nums){

            ans.push_back(to_string(num));
        }

        sort(ans.begin(), ans.end(), cmp);

        if(ans[0] == "0"){
            return "0";
        }

        string answer;

        for (string& s: ans){
            answer+=s;
        }

        return answer;
    }
};
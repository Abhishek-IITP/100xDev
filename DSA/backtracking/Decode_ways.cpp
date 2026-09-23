class Solution {
public:

    int fn(int curr, string& s, vector<int>& dp) {

        if(curr == s.size()) {
            return 1;
        }

        if(dp[curr] != -1) {
            return dp[curr];
        }

        int ways = 0;

        // Take one digit
        int digit = s[curr] - '0';

        if(digit >= 1 && digit <= 9) {
            ways += fn(curr + 1, s, dp);
        }

        // Take two digits
        if(curr + 1 < s.size()) {

            int num = (s[curr] - '0') * 10
                    + (s[curr + 1] - '0');

            if(num >= 10 && num <= 26) {
                ways += fn(curr + 2, s, dp);
            }
        }

        return dp[curr] = ways;
    }

    int numDecodings(string s) {

        vector<int> dp(s.size(), -1);

        return fn(0, s, dp);
    }
};
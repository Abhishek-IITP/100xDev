class Solution {
public:
    int longestValidParentheses(string s) {

        map<char, char> mp;

        mp[')'] = '(';

        stack<pair<char, int>> st;

        int ans = 0;
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (ch == '(') {
                st.push({ch, i});
            } else {
                if (!st.empty() && st.top().first == mp[ch]) {

                    st.pop();

                    if (st.empty()) {
                        count = i + 1;
                    }
                    else {
                        count = i - st.top().second;
                    }

                    ans = max(ans, count);
                }else{
                    st.push({ch,i});
                }
            }
        }
        return ans;
    }
};
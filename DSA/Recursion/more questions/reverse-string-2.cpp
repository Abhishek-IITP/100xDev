class Solution {
public:

    void helper(string& s, int start, int k){
        if(start >= s.size()) return;

        int left = start;
        int right = min(start + k - 1, (int)s.size() - 1);

        while(left<=right){
            swap(s[left],s[right]);

            left++;
            right--;
        } 

        helper(s,start+ 2*k,k);
    }
    string reverseStr(string s, int k) {
        helper(s,0,k);
        return s;
    }
};
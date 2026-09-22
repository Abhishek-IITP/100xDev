class Solution {
public:
    void helper(vector<int>& nums, vector<int>& ans, int idx) {

        if (idx == nums.size())
            return;

        if (nums[idx] != 0)
            ans.push_back(nums[idx]);

        helper(nums, ans, idx + 1);
    }
    void moveZeroes(vector<int>& nums) {

        vector<int> ans;
        helper(nums, ans, 0);

        while (ans.size() < nums.size()) {
            ans.push_back(0);
        }

        nums = ans;
    }
};
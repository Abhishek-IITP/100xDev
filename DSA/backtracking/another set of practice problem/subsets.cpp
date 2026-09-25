class Solution {
public:
    void fn(int i, int n, vector<int>& nums, vector<int>& path,
            vector<vector<int>>& ans) {
        if (i == n) {
            ans.push_back(path);
            return;
        }
        if (i >= n)
            return;

        // take
        path.push_back(nums[i]);
        fn(i + 1, n, nums, path, ans);
        path.pop_back();

        // not take
        fn(i + 1, n, nums, path, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {

        int n = nums.size();

        vector<int> path;

        vector<vector<int>> ans;

        fn(0, n, nums, path, ans);

        return ans;
    }
};
class Solution {
public:
    void fn( int n, vector<int>& nums, vector<int>& path,
            set<vector<int>>& ans, vector<bool>& used) {
        if (n == path.size()) {
            ans.insert(path);
            return;
        }

        if (path.size() > n)
            return;

        for (int i = 0; i < n; i++) {

            if (used[i])
                continue;

            used[i] = true;
            path.push_back(nums[i]);

            fn( n, nums, path, ans, used);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<int> path;
        set<vector<int>> ans;

        int n = nums.size();

        vector<bool> used(n, false);
        fn( n, nums, path, ans, used);

        vector<vector<int>> result(ans.begin(), ans.end());

        return result;
    }
};
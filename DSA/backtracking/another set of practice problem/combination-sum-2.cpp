class Solution {
public:
    void fn(int i, vector<int>& nums, vector<int>& path, set<vector<int>>& ans,
            int sum, int k) {

        if (sum == k) {
            ans.insert(path);
            return;
        }

        if (i >= nums.size() || sum > k)
            return;

        // take
        path.push_back(nums[i]);
        fn(i + 1, nums, path, ans, sum + nums[i], k);
        path.pop_back();

        // not take
        int next = i + 1;

        // Skip duplicate values
        while (next < nums.size() && nums[next] == nums[i]) {
            next++;
        }

        fn(next, nums, path, ans, sum, k);
    }


vector<vector<int>>
combinationSum2(vector<int>& candidates, int target) {

    sort(candidates.begin(), candidates.end());

    vector<int> path;
    set<vector<int>> ans;

    fn(0, candidates, path, ans, 0, target);

    vector<vector<int>> result(ans.begin(), ans.end());
    return result;
}
}
;
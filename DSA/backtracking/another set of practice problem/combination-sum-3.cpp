class Solution {
public:
    int calSum(vector<int>& nums) {
        int sum = 0;

        for (auto& num : nums) {
            sum += num;
        }

        return sum;
    }

    void fn(int start,int k, int n, vector<int>& path, vector<vector<int>>& ans) {

        if(path.size() == k) {
            if(calSum(path) == n) {
                ans.push_back(path);
            }
            return;        
        };

        for (int i = start; i < 10; i++) {

            path.push_back(i);
            fn(i+1,k, n, path, ans);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        vector<int> path;
        vector<vector<int>> ans;

        fn(1,k, n, path, ans);
        return ans;
    };
};
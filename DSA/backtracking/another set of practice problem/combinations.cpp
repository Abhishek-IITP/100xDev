class Solution {
public:
    void fn(int i, int n, int k, vector<int>& path,
            vector<vector<int>>& ans) {

        if (path.size() == k) {
            ans.push_back(path);
            return;
        }
        if (i > n)
            return;

        // take
        path.push_back(i);
        fn(i + 1, n, k, path, ans);
        path.pop_back();

        // not take
        fn(i + 1, n, k, path, ans);
    }
    vector<vector<int>> combine(int n, int k) {

        vector<int> path;
        vector<vector<int>> ans;

        fn(1, n, k, path, ans);
        return ans;
    }
};

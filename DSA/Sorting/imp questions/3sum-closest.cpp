class Solution {
public:

    void fn(int i, vector<int>& nums, int target, int& ans) {

        int n = nums.size();

        if(i >= n - 2)
            return;

        int l = i + 1;
        int r = n - 1;

        while(l < r) {

            int sum = nums[i] + nums[l] + nums[r];

            if(abs(sum - target) < abs(ans - target)) {
                ans = sum;
            }

            if(sum < target)
                l++;
            else if(sum > target)
                r--;
            else {
                ans = target;
                return;
            }
        }

        fn(i + 1, nums, target, ans);
    }

    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int ans = nums[0] + nums[1] + nums[2];

        fn(0, nums, target, ans);

        return ans;
    }
};
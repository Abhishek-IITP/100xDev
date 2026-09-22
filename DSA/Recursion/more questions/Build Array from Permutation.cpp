class Solution {
public:

    void helper(vector<int>& nums, vector<int>& ans, int i){
        if(i == nums.size()) return;

        ans[i]=  nums[nums[i]];

        helper(nums,ans,i+1);
    }
    vector<int> buildArray(vector<int>& nums) {

        int n = nums.size();

        vector<int>ans(n);

        helper(nums,ans,0);
    return ans;        
    }
};
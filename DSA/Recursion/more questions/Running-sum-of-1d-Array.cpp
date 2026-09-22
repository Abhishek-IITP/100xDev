class Solution {
public:

int helper(vector<int>& nums, vector<int>& ans,int i){

    if(i == 0){
        ans[0] = nums[0];
        return ans[0];
    }

    int smallAns = helper(nums,ans,i-1);
    ans[i]= smallAns + nums[i];
    return ans[i]; 

}
    vector<int> runningSum(vector<int>& nums) {

        int n = nums.size();

        vector<int>ans(n);

        helper(nums,ans,n-1);        
    return ans;
    }
};
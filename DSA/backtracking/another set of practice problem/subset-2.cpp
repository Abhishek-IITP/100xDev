class Solution {
public:
    void fn(int i , int n , vector<int>& nums, vector<int>& path,set<vector<int>>& ans){


        if(i == n){
            ans.insert(path);
            return;
        }
         
        //take

        path.push_back(nums[i]);
        fn(i+1,n,nums,path,ans);
        path.pop_back();


        //not take

        fn(i+1,n,nums,path,ans);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>path;
        set<vector<int>> ans;

        int n = nums.size();

        fn(0,n,nums,path,ans);

        //convert set to vector
        vector<vector<int>> result(ans.begin(), ans.end());

        return result;

    }
};
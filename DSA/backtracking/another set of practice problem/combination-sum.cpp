class Solution {
public:
    int calSum(vector<int>& nums){
        int sum =0;
        for(auto& num: nums){
            sum+=num;
        }
        return sum;
    }

    void fn(int i, vector<int>& candidates, vector<int>& path,vector<vector<int>>& ans, int target ){

        int sum = calSum(path);
        if(target == sum){
            ans.push_back(path);
            return;
        }
        if(sum > target) return;

        if(i>= candidates.size()) return;

        //take
        path.push_back(candidates[i]);
        fn(i,candidates, path,ans,target);
        path.pop_back();

        //not take
        fn(i+1,candidates, path,ans,target);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        

        vector<int>path;
        vector<vector<int>>ans;


        fn(0,candidates,path,ans,target);

        return ans;
        
    }
};
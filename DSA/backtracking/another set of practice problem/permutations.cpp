class Solution {
public:
void fn(vector<int>& nums,vector<int>& path,vector<vector<int>>& ans,vector<bool>& used){

    if(nums.size() == path.size()){
        ans.push_back(path);
        return;
    }

    for(int i =0;i<nums.size();i++){

        if(used[i]) continue;

        //take
        used[i]= true;
    path.push_back(nums[i]);
    fn(nums,path,ans,used);
    
    //backtrack
    path.pop_back();
        used[i]= false;
    }

}
    vector<vector<int>> permute(vector<int>& nums) {

        vector<int>path;
        vector<vector<int>>ans;
        vector<bool>used(nums.size(),false);

        fn(nums,path,ans,used);

        return ans;
        
    }
};
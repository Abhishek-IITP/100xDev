class Solution {
public:

    int merge(int l, int r, vector<int>& nums){

        int mid = l+ (r-l)/2;
        int j = mid+1;
        int count =0;

        for(int i =l;i<=mid;i++){
            while(j<=r && nums[i]> 2LL*nums[j]){
                j++;
            }
            count += j - (mid+1);
        }

        int i = l;
        j = mid+1;
        vector<int>temp;


        while(i<=mid && j<= r){

            if(nums[i]<nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }

    while(i<=mid){
        temp.push_back(nums[i]);
        i++;
    }
    while(j<=r){
        temp.push_back(nums[j]);
        j++;
    }

    for(int k =0;k< temp.size();k++){
        nums[l+k] = temp[k];
    }
    return count;
    }

    int fn(int l,int r,vector<int>& nums){

        if(l>=r) return 0;
        int mid = l+ (r-l)/2;

        int ans1 =fn(l,mid,nums);

        int ans2 =fn(mid+1,r,nums);

        int ans3= merge(l,r,nums);

        return ans1+ans2+ans3;
    }

    int reversePairs(vector<int>& nums) {
        
        int n = nums.size();
        int ans=fn(0,n-1,nums);

        return ans;
    }
};
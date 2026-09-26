class Solution {
public:
void  merge(int l,int r,vector<int>& nums){

    int mid = l+ (r-l)/2;

    int i =l;
    int j = mid +1;

    vector<int> temp;

    while(i<=mid && j<=r ){

        if(nums[i]<=nums[j]){
            temp.push_back(nums[i]);
            i++;
        }else{
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
    for (int k = 0; k < temp.size(); k++) {
            nums[l + k] = temp[k];
        }
}

void fn(int l,int r,vector<int>& nums){

    if(l >= r) return;

    int mid = (l+r)/2;

    // sort the first half

    fn(l,mid,nums);

    // sort the second half

    fn(mid+1,r,nums);

    merge(l,r,nums);

}
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        fn(0,n-1,nums);

        return nums;
        
    }
};
class Solution {
public:
    void fn(int i, int j, int k, vector<int>& nums1, vector<int>& nums2) {
        if (j<0) return;  // nums3 is completely merged

        if(i<0){
            nums1[k] = nums2[k];
            fn(i,j-1,k-1,nums1,nums2);
            return;
        }

        if(nums1[i]>nums2[j]){
            nums1[k] = nums1[i];
            fn(i-1,j,k-1,nums1,nums2);
        }else{
            nums1[k] = nums2[j];
            fn(i,j-1,k-1,nums1,nums2);
        }

    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        fn(m-1, n-1,m+n-1, nums1, nums2);
    
    }
};
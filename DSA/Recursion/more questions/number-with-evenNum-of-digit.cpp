class Solution {
public:
    void helper(vector<int>& nums, int n, int& c) { 
        
        if(n < 0) 
            return; 

        int digitCount;

        if(nums[n] == 0)
            digitCount = 1;
        else
            digitCount = (int)log10(nums[n]) + 1;

        if(digitCount % 2 == 0)
            c++;

        helper(nums, n - 1, c);
    }

    int findNumbers(vector<int>& nums) {

        int n = nums.size();
        int count = 0;

        helper(nums, n - 1, count);

        return count;
    }
};
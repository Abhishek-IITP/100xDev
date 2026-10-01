class Solution {
public:
    int findGCD(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());

        int smallestNumber = nums[0];
        int largestNumber = nums[nums.size()-1];

        return std::gcd(smallestNumber,largestNumber);
        
    }
};
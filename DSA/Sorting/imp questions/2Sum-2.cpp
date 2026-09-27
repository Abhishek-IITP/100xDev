class Solution {
public:

     vector<int> solve(vector<int>& numbers, int target, int i, int j) {

        if(i>=j){
            return {};
        }
        int sum = numbers[i] + numbers[j];

        if(sum == target){
            return {i+1,j+1};
        }
        if(sum<target){
            return solve(numbers, target,i+1,j);
        }

        return solve(numbers, target, i, j - 1);

    }

    vector<int> twoSum(vector<int>& numbers, int target) {

        int n = numbers.size();
        return solve(numbers,target,0,n-1);
    }
};
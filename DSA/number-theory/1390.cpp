class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans =0;

        for(int num:nums){

            int sum =0;
            int count =0;

            for(int i =1;i*i<=num;i++){

                if(num%i ==0){
                    int j = num/i;
                    count++;
                    sum+=i;

                    if(i != j){
                        count++;
                        sum+=j;
                    }
                }
            }
            if(count ==4){
                ans += sum;
            }
        }
        return ans;
        
    }
};
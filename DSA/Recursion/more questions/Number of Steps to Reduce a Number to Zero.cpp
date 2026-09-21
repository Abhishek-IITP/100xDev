class Solution {
public:
    int helper(int n, int x){
        if(n==0) return x;

        if(n%2 ==0){
            x++;
            return helper(n/2,x);
        }else{
            x++;
            return helper(n-1,x);
        }
    }
    int numberOfSteps(int num) {
        int count=0;
        return helper(num,count);
    }
};
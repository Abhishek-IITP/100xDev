class Solution {
public:

    bool helper(int n){
        if(n==1) return true;
        if(n<=0 || n%2 != 0) return false;

        return helper(n/2);
    }
    bool isPowerOfFour(int n) {
        return helper(n);
        
    }
};
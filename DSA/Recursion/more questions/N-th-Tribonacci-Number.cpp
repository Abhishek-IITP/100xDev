class Solution {
public:

int helper(int n, int a, int b, int c){
    if( n ==0) return a;
    if(n == 1) return b;
    if(n == 2) return c;

    return helper(n-1, b,c,a+b+c);
}
    int tribonacci(int n) {
        return helper(n,0,1,1);
    }
};
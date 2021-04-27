class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        int x = pow(3, (int)(log(INT_MAX)/log(3)));
        // cout<<x<<endl;
        return x%n==0;
    }
};
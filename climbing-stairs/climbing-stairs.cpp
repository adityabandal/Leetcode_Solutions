class Solution {
public:
    int climbStairs(int n) {
        int f = 1;
        int s = 1;
        if(n==1) return 1;
        for(int i=2;i<=n;i++){
            s = f+s;
            f = s-f;
        }
        return s;
    }
};
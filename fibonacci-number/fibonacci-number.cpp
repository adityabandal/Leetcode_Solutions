class Solution {
public:
    int fib(int n) {
        int f = 0;
        int s = 1;
        if(n==0) return f;
        if(n==1) return s;
        for(int i=2;i<=n;i++){
            s = s+f;
            f = s-f;
        }
        return s;
    }
};
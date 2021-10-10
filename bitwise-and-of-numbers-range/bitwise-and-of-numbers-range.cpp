class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m==n || m==0) return m;
        
        int k=m;
        int p=1;
        while(m<n){
            n -= n  & -n;
        }
        return n;
    }
};
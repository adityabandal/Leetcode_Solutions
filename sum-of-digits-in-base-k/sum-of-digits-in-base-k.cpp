class Solution {
public:
    int sumBase(int n, int k) {
        int ans = 0;
        long long int p = k;
        while(n){
            ans += n%p;
            n /=p;
        }
        return ans;
    }
};
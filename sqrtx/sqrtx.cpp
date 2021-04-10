class Solution {
public:
    int mySqrt(int x) {
        long long int lo = 0, hi=x;
        long long int ans;
        while(lo<=hi){
            long long int mid = lo + (hi-lo)/2;
            if(mid*mid == x) return mid;
            else if(mid*mid<x){
                ans = mid;
                lo = mid+1;
            }
            else{
                hi = mid -1;
            }
        }
        return ans;
    }
};
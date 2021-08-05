#define ll unsigned long long
class Solution {
public:
    ll items(vector<int>& sup, int k){
        ll tot = 0;
        for(int i=0;i<sup.size();i++){
            if(sup[i]>=k){
                tot += (sup[i]-k+1);
            }
        }
        return tot;
    }
    ll sum(ll n, ll m){
        return (n*(n+1)/2)-(m*(m+1)/2);
    }
    int maxProfit(vector<int>& sup, int orders) {
        int mx = 0;
        int M = 1e9+7;
        int n = sup.size();
        for(int i=0;i<n;i++){
            mx = max(mx, sup[i]);
        }

        int lo=0, hi = mx;
        int thresh = 0;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(items(sup, mid)<=orders){
                thresh = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        ll ans = 0;
        for(int i=0;i<n;i++){
            if(sup[i]>=thresh){
                ans = (ans+sum(sup[i], thresh-1)%M)%M;
                orders -= (sup[i]-thresh+1);
            }
        }
        if(orders){
            ans = (ans+(ll)orders*(thresh-1)%M);
        }
        return ans%M;
    }
};
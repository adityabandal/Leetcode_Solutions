#define M 1000000007
#define ll long long int
class Solution {
public:
    bool valid(vector<int>& inv, int ord, int k){
        ll tot = 0;
        for(int i=0;i<inv.size();i++){
            if(inv[i]>=k){
                tot += inv[i]-k+1;
                if(tot>=ord) return true;
            }
        }
        return tot>=ord;
    }
    int maxv(const vector<int>& arr){
        int mx = INT_MIN;
        for(int a:arr){
            mx = max(mx, a);
        }
        return mx;
    }
    ll sum(ll n, ll m){
        return (n*(n+1)/2)-(m*(m+1)/2);
    }
    int maxProfit(vector<int>& inv, int ord) {
        ll lo = 1;
        ll hi = maxv(inv);
        int k = INT_MAX;
        while(lo<=hi){
            ll mid = lo+(hi-lo)/2;
            
            if(valid(inv, ord, mid)){
                k = mid;
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        ll ans = 0;
        for(int i=0;i<inv.size();i++){
            if(inv[i]>k){
                ord -= inv[i]-k;
                ans = (ans+sum(inv[i],k))%M;
            }
            
        }
        if(ord){
            ans =  (ans+((ll)ord*(ll)k)%M)%M;
        }
        // cout<<endl;
        return ans%M;
    }
};
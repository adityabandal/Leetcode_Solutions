class Solution {
public:
    bool help(vector<int>& w, int D, int c){
        int days = 0;
        int curr = 0;
        for(int i=0;i<w.size();i++){
            curr += w[i];
            if(curr > c){
                days++;
                curr = w[i];
            }
        }
        return days+1<=D;
    }
    int shipWithinDays(vector<int>& weights, int D) {
        int mx = INT_MIN, sum = 0;
        for(int w:weights){
            sum+=w;
            mx = max(mx, w);
        }
        int lo = mx, hi = sum;
        int ans = -1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            
            if(help(weights, D, mid)){
                // cout<<mid<<" ";
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        // cout<<endl;
        return ans;
    }
};
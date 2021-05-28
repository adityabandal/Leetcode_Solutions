#define ll long long
#define M 1000000007
class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        hc.push_back(h);
        sort(hc.begin(), hc.end());
        vc.push_back(w);
        sort(vc.begin(), vc.end());
        int mh = hc[0], mv=vc[0];
        for(int i=1;i<hc.size();i++){
            mh = max(mh, hc[i]-hc[i-1]);
        }
        for(int i=1;i<vc.size();i++){
            mv = max(mv, vc[i]-vc[i-1]);
        }
        return ((ll)mh*(ll)mv)%M;
    }
};
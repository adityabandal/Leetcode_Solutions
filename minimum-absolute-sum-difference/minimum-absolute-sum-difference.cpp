#define M 1000000007
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        // priority_queue<pair<int, int>> pq;
        
        int n = nums1.size();
        int lar = -1;
        int lar_val = INT_MIN;
        long ans = 0;
        for(int i=0;i<n;i++){
            ans = (ans + abs(nums1[i]-nums2[i]))%M;
            if(abs(nums1[i]-nums2[i]) > lar_val){
                lar_val = abs(nums1[i]-nums2[i]);
                lar = i;
            }
            s.insert(nums1[i]);
        }
        
        ans = (ans - lar_val)%M;
        // cout<<lar<<endl;
        auto it = s.lower_bound(nums2[lar]);
        if(it==s.end()){
            ans = (ans + abs(nums2[lar]-*s.rbegin()))%M;
        }
        else{
            int diff = abs(nums2[lar]-*it);
            if (it!=s.begin()){
                it--;
                diff = min(diff, abs(nums2[lar]-*it));
            }
            ans =  (ans+diff)%M;
        }
        return ans;
    }
};
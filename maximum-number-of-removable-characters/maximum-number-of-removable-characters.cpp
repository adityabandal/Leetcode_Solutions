class Solution {
public:
    unordered_set<int> bl;
    bool isSub(string s, string p){
        int l1 = s.size(), l2 = p.size();
        int i=0, j=0;
        while(i<l1 && j<l2){
            if(bl.count(i)) {i++;continue;}
            if(s[i]==p[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return j == l2;
    }
    int maximumRemovals(string s, string p, vector<int>& rem) {
        int n = rem.size();
        int lo =0, hi = n-1;
        int ans=-1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            bl.clear();
            for(int i=0;i<=mid;i++){
                bl.insert(rem[i]);
            }
            if(isSub(s,p)){
                ans = mid;
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        return ans+1;
    }
};
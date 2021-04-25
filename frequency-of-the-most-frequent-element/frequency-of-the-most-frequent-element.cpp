class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int n:nums){
            m[n]++;
        }
        
        vector<pair<int, int>> s;
        for(auto p:m){
            s.push_back({p.first, p.second});
        }
        sort(s.begin(), s.end());
        
        int ans = 0;
        for(int i=0;i<s.size();i++){
            int f = m[s[i].first];
            int x = k;
            for(int j=i-1;j>=0 && k>0;j--){
                int diff = s[i].first - s[j].first;
                int add = min(s[j].second, x/diff);
                x -= diff*add;
                f += add;
                if(add == 0) break;
            }
            ans = max(f, ans);
        }
        
        return ans;
    }
};
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> m;
        multiset<int> s;
        for(int a:arr){
            m[a]++;
        }
        
        for(auto p:m){
            s.insert(p.second);
        }
        
        
        int n = arr.size();
        int ans = 0;
        int t = 0;
        for(auto it=s.rbegin();it!=s.rend();it++){
            t+=*it;
            ans++;
            if(t>=n/2) return ans;
        }
        return ans;
    }
};
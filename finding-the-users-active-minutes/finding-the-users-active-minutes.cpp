class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> m;
        for(auto& p:logs){
            m[p[0]].insert(p[1]);
        }
        vector<int> ans(k, 0);
        for(auto p:m){
            if(p.second.size()<=k){
                ans[p.second.size()-1]++;
            }
        }
        return ans;
    }
};
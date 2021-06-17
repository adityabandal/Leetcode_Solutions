class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        unordered_map<int, priority_queue<int>> m;
        for(auto i:items){
            m[i[0]].push(i[1]);
        }
        
        vector<vector<int>> ans;
        for(auto x:m){
            int cnt = 5;
            int sum = 0;
            while(cnt--){
                sum+=x.second.top();
                x.second.pop();
            }
            ans.push_back({x.first, sum/5});
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};
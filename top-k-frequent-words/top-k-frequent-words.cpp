struct Compare{
    bool operator()(const pair<int, string>& p1, const pair<int, string>& p2){
        if(p1.first == p2.first){
            return p1.second > p2.second;
        }
        else{
            return p1.first < p2.first;
        }
    }
};
class Solution {
public:
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq;
        unordered_map<string, int> m;
        
        for(int i=0;i<words.size();i++){
            m[words[i]]++;
        }
        
        for(auto p:m){
            pq.push({p.second, p.first});
        }
        
        vector<string> ans;
        
        while(k--){
            // cout<<pq.top().second<<" "<<pq.top().first<<endl;
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
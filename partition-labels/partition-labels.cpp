class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> m;
        int n = s.size();
        
        for(int i=0;i<n;i++){
            m[s[i]] = i;
        }
        int start = 0;
        int mx = -1;
        vector<int> ans;
        for(int i=0;i<n;i++){
            mx = max(mx, m[s[i]]);
            if(mx == i){
                ans.push_back(i-start+1);
                start = i+1;
            }
        }
        return ans;
    }
};
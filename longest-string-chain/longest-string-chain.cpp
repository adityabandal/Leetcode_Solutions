class Solution {
public:
    unordered_set<string> s;
    unordered_map<string, int> dp;
    int help(string word){
        if(word == "") return 0;
        if(dp.find(word)!=dp.end()) return dp[word];
        int n = word.size();
        int ans = 1;
        for(int i=0;i<n;i++){
            string tmp = word;
            tmp.erase(tmp.begin()+i);
            if(s.count(tmp)){
                ans = max(ans, 1+help(tmp));
            }
        }
        return dp[word] = ans;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end());
        for(string& w:words) s.insert(w);
        s.insert("");
        int ans = 1;
        for(int i=words.size()-1;i>=0;i--){
            ans = max(ans, help(words[i]));
        }
        return ans;
    }
};
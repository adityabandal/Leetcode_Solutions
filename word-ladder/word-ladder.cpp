class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string, vector<string>> m;
        for(string w:wordList){
            for(int i=0;i<w.size();i++){
                string tmp = w;
                tmp[i] = '*';
                m[tmp].push_back(w);
            }
        }
        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        int steps = 1;
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                string w = q.front();
                q.pop();
                
                if(visited.find(w)!=visited.end()) continue;
                // cout<<w<<" ";
                if(w == endWord) return steps;
                visited.insert(w);
                for(int i=0;i<w.size();i++){
                    string tmp = w;
                    tmp[i] = '*';
                    for(string s:m[tmp]){
                        q.push(s);
                    }
                }
            }
            // cout<<endl;
            steps++;
        }
        return 0;
    }
};
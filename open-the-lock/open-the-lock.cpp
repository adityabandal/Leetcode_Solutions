class Solution {
public:
    unordered_set<string> dead;
    int openLock(vector<string>& deadends, string target) {
        for(string s:deadends){
            dead.insert(s);
        }
        
        queue<string> q;
        q.push("0000");
        unordered_set<string> visited;
        
        int steps = 0;
        while(!q.empty()){
            int s = q.size();
            
            for(int i=0;i<s;i++){
                string l = q.front(); q.pop();
                if(visited.find(l)!=visited.end()) continue;
                if(dead.find(l)!=visited.end()) continue;
                if(l == target) return steps;
                visited.insert(l);
                // cout<<l<<" ";
                for(int j=0;j<4;j++){
                    int d = l[j]-'0';
                    int d1 = d+1;
                    if(d1>9) d1-=10;
                    int d2 = d-1;
                    if(d2<0) d2+=10;
                    
                    string nxt = l;
                    nxt[j] = d1+'0';
                    q.push(nxt);
                    nxt[j] = d2+'0';
                    q.push(nxt);
                }
            }
            steps++;
            // cout<<endl;
        }
        return -1;
    }
};
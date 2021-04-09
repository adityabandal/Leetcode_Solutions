class Solution {
public:
    unordered_map<char, int> m;
    bool comp(string& a, string& b){
        int l1 = a.size();
        int l2 = b.size();
        int i=0;
        while(i<l1 && i<l2){
            if(m[a[i]] == m[b[i]]){
                i++;
            }
            else if(m[a[i]] < m[b[i]]){
                return true;
            }
            else{
                return false;
            }
        }
        return i==l1;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0;i<order.size();i++){
            m[order[i]] = i;
        }
        for(int i=1;i<words.size();i++){
            if(comp(words[i-1], words[i])) continue;
            else return false;
        }
        return true;
    }
};
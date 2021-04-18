class Solution {
public:
    bool checkIfPangram(string s) {
        vector<bool> a(26, 0);
        for(char c:s){
            a[c-'a'] = true;
        }
        for(int i=0;i<26;i++){
            if(!a[i]) return false;
        }
        return true;
    }
};
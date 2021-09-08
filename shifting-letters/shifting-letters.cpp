class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        shifts[n-1]%=26;
        for(int i=shifts.size()-2;i>=0;i--){
            shifts[i] += shifts[i+1];
            shifts[i]%=26;
        }
        
        for(int i=0;i<s.size();i++){
            int x = ((s[i]-'a')+shifts[i])%26;
            s[i] = 'a'+x;
        }
        return s;
    }
};
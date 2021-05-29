class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int c[26];
        memset(c, 0, sizeof(c));
        for(int i =0;i<chars.size();i++){ // l2
            c[chars[i]-'a']++;
        }
        
        int w[26];
        int ans = 0;
        for(int i=0;i<words.size();i++){  // n
            memset(w, 0, sizeof(w));
            for(int j=0;j<words[i].size();j++){ // l1
                w[words[i][j]-'a']++;
            }
            bool valid = true;
            for(int j=0;j<26;j++){ //26
                if(w[j]>c[j]){
                    valid = false;
                    break;
                }
            }
            if(valid){
                ans+=words[i].size();
            }
            
        }
        // TC = O(l2 + n*(l1+26)) = O(n.l1)
        return ans;
    }
};
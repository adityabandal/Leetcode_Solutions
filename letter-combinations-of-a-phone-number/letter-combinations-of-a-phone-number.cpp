class Solution {
public:
    map<int,set<char>> m;
    void generate(string digits, vector<string>& ans,int i,string seq){
        if(i<0 || i>digits.size()) return;
        else if(i==digits.size()) ans.push_back(seq);
        else{
            int n = digits[i]-'0';
            for(char c:m[n]){
                string temp = seq;
                temp.push_back(c);
                generate(digits,ans,i+1,temp);
            }
        }
        
    }
    vector<string> letterCombinations(string digits) {
        
        m[2] = {'a','b','c'};
        m[3] = {'d','e','f'};
        m[4] = {'g','h','i'};
        m[5] = {'j','k','l'};
        m[6] = {'m','n','o'};
        m[7] = {'p','q','r','s'};
        m[8] = {'t','u','v'};
        m[9] = {'w','x','y','z'};
        // for(char c:m[9]){
        //     cout<<c;
        // }
        vector<string> ans;
        if(digits.size()==0) return ans;
        generate(digits,ans,0,"");
        return ans;
    }
};
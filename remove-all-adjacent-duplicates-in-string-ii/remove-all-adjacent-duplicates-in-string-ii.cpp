class Solution {
public:
    string removeDuplicates(string s, int k) {
        string prev = "";
        string curr = s;
        while(curr.size()>=k && curr!=prev){
            string tmp = "";
            int cnt = 1;
            char ch = curr[0];
            for(int i=1;i<curr.size();i++){
                if(curr[i]==ch){
                    cnt++;
                }
                else{
                    for(int j=0;j<cnt%k;j++){
                        tmp.push_back(ch);
                    }
                    ch = curr[i];
                    cnt = 1;
                }
            }
            for(int j=0;j<cnt%k;j++){
                tmp.push_back(ch);
            }
            
            prev = curr;
            curr = tmp;
        }
        return curr;
    }
};
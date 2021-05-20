class Solution {
public:
    vector<vector<int>> ans;
    void help(int n, int k, vector<int>& seq, int curr){
        if(curr>n+1) return;
        // if(seq.size()>k) return;
        if(seq.size()==k){
            ans.push_back(seq);
        }
        else{
            help(n, k, seq, curr+1);
            seq.push_back(curr);
            help(n, k, seq, curr+1);
            seq.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> seq;
        help(n,k,seq,1);
        return ans;
    }
};
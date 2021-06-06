class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> m;
        for(int n:nums){
            m[n]++;
        }
        int longest = 0;
        for(auto p:m){
            if(!m[p.first-1]){
                int currnum = p.first;
                int currlen = 1;
                while(m[currnum+1]>0){
                    currnum++;
                    currlen++;
                }
                longest = max(longest, currlen);
            }
        }
        return longest;
    }
};
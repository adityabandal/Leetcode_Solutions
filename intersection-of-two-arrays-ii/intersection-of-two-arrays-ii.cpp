class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> m;
        for(int n:nums1){
            m[n]++;
        }
        for(int n:nums2){
            if(m[n]>0){
                m[n]--;
                ans.push_back(n);
            }
        }
        return ans;
    }
};
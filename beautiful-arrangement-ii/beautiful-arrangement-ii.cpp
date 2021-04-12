class Solution {
public:
    
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        int lo=1, hi=n;
        /*
            fill 1, n, 2, n-1.... alternatively till we get k-1 unique differences, i.e after k elements
            fill remaining elements [lo, hi] in increasing or decreasing order depending on the value of the last element of the array
        */
        for(int i=0;i<k;i++){
            if(i%2==0) ans.push_back(lo++);
            else ans.push_back(hi--);
        }
        if(ans.back()==lo-1)
            for(int i=lo;i<=hi;i++) ans.push_back(i);
        else
            for(int i=hi;i>=lo;i--) ans.push_back(i);
        return ans;
    }
};
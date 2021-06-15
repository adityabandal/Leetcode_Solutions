class Solution {
public:
    
    bool dfs(vector<int>& m, vector<int>& sides, int idx, int mx){
        if(idx == m.size()){
            return sides[0]==sides[1] && sides[1]==sides[2] && sides[2]==sides[3];
        }
        
        for(int i=0;i<4;i++){
            if(sides[i]+m[idx]>mx) continue;
            sides[i]+=m[idx];
                if(dfs(m,sides,idx+1,mx)) return true;
            sides[i]-=m[idx];
        }
        return false;
    }
    bool makesquare(vector<int>& nums) {        
        int sum = 0;
        for(const int x:nums) sum+=x;
        if(sum%4!=0) return false;
        
        sort(nums.begin(), nums.end(), greater<int>());

        vector<int> sides(4,0);
        return dfs(nums, sides, 0, sum/4);
    }
};
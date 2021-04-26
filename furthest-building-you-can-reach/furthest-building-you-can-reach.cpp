class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = heights.size();
        for(int i=0;i<n-1;i++){
            int d = heights[i+1] - heights[i];
            if(d<=0) continue;
            pq.push(d);
            if(ladders){
                ladders--;
            }
            else{
                int small = pq.top();
                pq.pop();
                if(small > bricks) return i;
                else{
                    bricks -= small;
                }
            }
        }
        return n-1;
    }
};
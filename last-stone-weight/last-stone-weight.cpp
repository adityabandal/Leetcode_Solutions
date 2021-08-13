class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        make_heap(stones.begin(), stones.end());
        while (stones.size() > 1) {
            int y = stones.front(); //[stones.size() - 1];
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            int x = stones.front(); //[stones.size() - 1];
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            if (x != y) {
                stones.push_back(y - x);
                push_heap(stones.begin(), stones.end());
            }
        }
        return accumulate(stones.begin(), stones.end(), 0);
    }
};
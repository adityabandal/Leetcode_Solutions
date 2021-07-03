class Solution {
public:
    int distributeCandies(vector<int>& candType) {
        unordered_set<int> s;
        int sum = candType.size();
        for(int& c:candType){
            s.insert(c);
        }
        return min(sum/2, (int)s.size());
    }
};
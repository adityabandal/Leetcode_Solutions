class Solution {
public:
    int minOperations(int n) {
        int sum = 0;
        for(int i=0;i<n/2;i++){
            sum+= n-(2*i+1);
        }
        return sum;
    }
};
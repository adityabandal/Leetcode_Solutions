class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int a[n];
 
        for(int i = 0; i < n; i++)
        {
            a[i] = (s[i] == '1' ? 1 : 0);
        }

        int oddone[n + 1];
        int evenone[n + 1];

        oddone[0] = 0;
        evenone[0] = 0;

        for(int i = 0; i < n; i++)
        {
            if (i % 2 != 0){
                oddone[i + 1] = oddone[i] + (a[i] == 1 ? 1 : 0);
                evenone[i + 1] = evenone[i] + (a[i] == 0 ? 1 : 0);
            }
            else{
                oddone[i + 1] = oddone[i] + (a[i] == 0 ? 1 : 0);
                evenone[i + 1] = evenone[i] + (a[i] == 1 ? 1 : 0);
            }
        }

        int minimum = min(oddone[n], evenone[n]);
        if (n % 2 != 0){
            for(int i = 0; i < n; i++){
                minimum = min(minimum, oddone[n] - oddone[i + 1] + evenone[i + 1]);
                minimum = min(minimum, evenone[n] - evenone[i + 1] + oddone[i + 1]);
            }
        }
        return minimum;
    }
};
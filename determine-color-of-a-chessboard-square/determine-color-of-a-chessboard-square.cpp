class Solution {
public:
    bool squareIsWhite(string c) {
        return ((c[0]-'a')+(c[1]-'0'))%2==0;
    }
};
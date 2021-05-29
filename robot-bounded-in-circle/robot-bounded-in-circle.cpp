class Solution {
public:
    bool isRobotBounded(string in) {
        int step[4] = {};
        /*
            N W S E
            R = ++
            L = --
        */
        int d = 0;
        for(char c:in){
            if(c == 'G'){
                step[d]++;
            }
            else if(c == 'L'){
                d--;
                if(d<0) d+=4;
            }
            else{
                d = (d+1)%4;
            }
        }
        
        int x = step[1]-step[3];
        int y = step[0]-step[2];
        
        return d!=0 || (x==0 && y==0); 
    }
};
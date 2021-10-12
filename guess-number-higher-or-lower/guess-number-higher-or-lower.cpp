/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
#define ll long long int
class Solution {
public:
    int guessNumber(int n) {
        ll lo=1;
        ll hi=n;
        ll mid;
        while(lo<=hi){
            mid = (lo+hi)/2;
            int x = guess(mid);
            if(x==0) return mid;
            if(x==-1){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return lo;
    }
};
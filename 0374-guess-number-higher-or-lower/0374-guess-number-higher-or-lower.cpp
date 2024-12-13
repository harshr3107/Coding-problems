/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        
        int i=1;
        int j=n;
        
        while(j>=i)
        {
            long long mid = (static_cast<long long>(i)+static_cast<long long>(j))/2;
            
            if(guess(mid)==0)
            {
                return mid;
            }
            
            if(guess(mid)==-1)
            {
                j=mid-1;
            }else{
                
                i=mid+1;
            }
            
        }
        
        
        return 0;
        
        
        
    }
};
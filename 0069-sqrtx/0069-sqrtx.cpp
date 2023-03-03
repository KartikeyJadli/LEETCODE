class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1){
            return x;
        }

        long low = 1, high = (long)x, sqr = 0, mid = 0;
        
        while(low <= high){
            long mid = (low + high)/2;
            long sq = mid * mid;
            if(x == sq){
                return mid;
            }

            else if(sq < x){
                sqr = mid;
                low = mid + 1;
            }

            else{
                high = mid - 1;
            }
        }

        return (int)high;
    }
};
class Solution {
public:
    int binarysearch(int n){
        if(n == 1){
            return 1;
        }

        int low = 1,high = n/2;
        while(low <= high){
            int mid = low + (high - low)/2;
            int temp = n/mid;

            if(mid == temp){
                return mid;
            }

            else if(mid < temp){
                low = mid + 1;
            }

            else{
                high = mid - 1;
            }
        }

        return low - 1;
    }

    int bulbSwitch(int n) {
        return binarysearch(n);
    }
};
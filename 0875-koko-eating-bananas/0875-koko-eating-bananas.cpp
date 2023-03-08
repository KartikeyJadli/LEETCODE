class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1,high = 1e9,k = 0;

        while(low < high){
            int mid = (low + high)/2;
            int total = 0;

            for(auto x: piles){
                total += (x + mid - 1)/mid;
            }

            if(total > h){
                low = mid + 1;
            }

            else{
                high = mid;
            }

            k = low;
        }

        return k;
    }
};
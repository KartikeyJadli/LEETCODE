class Solution {
public:
    int pbinarysearch(vector<int> &v,int low,int high){
        int idx = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(v[mid] <= 0){
                low = mid + 1;
            }

            else{
                high = mid - 1;
                idx = mid;
            }
        }

        return idx;
    }

    int nbinarysearch(vector<int> &v,int low,int high){
        int idx = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(v[mid] < 0){
                low = mid + 1;
                idx = mid;
            }

            else{
                high = mid - 1;
            }
        }

        return idx;
    }

    int maximumCount(vector<int>& nums) {
        int low = 0,high = nums.size();
        if(high == 1){
            return 1;
        }

        int count1 = pbinarysearch(nums,low,high-1);
        int count2 = nbinarysearch(nums,low,high-1);

        if(count1 == -1 && count2 == -1){
            return 0;
        }

        if(count1 == -1 || count2 == -1){
            return high;
        }

        int p = (high-1)-count1+1;
        int n = count2+1;

        return max(p,n);
    }
};
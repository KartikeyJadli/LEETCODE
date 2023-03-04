class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long sub = 0;

        bool mn = false,mx = false;
        int mins = 0,mxs = 0,start = 0,n = nums.size();

        for(int i=0;i<n;i++){
            int temp = nums[i];
            if(temp < minK || temp > maxK){
                mn = false;
                mx = false;
                start = i + 1;
            }

            if(temp == minK){
                mn = true;
                mins = i;
            }

            if(temp == maxK){
                mx = true;
                mxs = i;
            }

            if(mn && mx){
                sub += (min(mins,mxs) - start + 1);
            }
        }

        return sub;
    }
};
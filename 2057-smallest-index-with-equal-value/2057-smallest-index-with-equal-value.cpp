class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        int n = nums.size(),idx = INT_MAX;
        for(int i=0;i<n;i++){
            if(i % 10 == nums[i]){
                idx = min(idx,i);
            }
        }

        if(idx == INT_MAX){
            return -1;
        }

        return idx;
    }
};
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        if(nums.size() == 1){
            return nums;
        }

        int n = nums.size();
        vector<int> v = {};
        for(int i=0;i<n;i++){
            v.insert(v.begin() + index[i],nums[i]);
        }

        return v;
    }
};
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool ascending = true, descending = true;
        int i, size = nums.size() - 1;
        
        for (i=0;i<size;i++) {
            if (ascending && nums[i] > nums[i+1]) {
                ascending = false;
            }
            
            if (descending && nums[i] < nums[i+1]) {
                descending = false;
            }
        }
        
        return ascending || descending;
    }
};
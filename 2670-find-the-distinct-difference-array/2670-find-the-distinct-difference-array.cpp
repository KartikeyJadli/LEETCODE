class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        set<int> s1,s2;

        for(int i=0; i<n; i++){
            s1.insert(nums[i]);
            for(int j=i+1;j<n;j++){
                s2.insert(nums[j]);
            }

            nums[i] = s1.size() - s2.size();
            s2.clear();
        }
        
        return nums;
    }
};
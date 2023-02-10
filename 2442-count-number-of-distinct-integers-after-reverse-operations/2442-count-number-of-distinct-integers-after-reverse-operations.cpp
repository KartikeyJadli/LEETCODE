class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        set<int> s;

        for(auto x: nums){
            s.insert(x);
        }

        for(int i=0;i<nums.size();i++){
            int sum = 0,rem;

            while(nums[i] > 0){
                rem = nums[i] % 10;
                sum = sum * 10 + rem;
                nums[i] = nums[i]/10;
            }

            s.insert(sum);
        }

        return s.size();
    }
};
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto i: nums){
            sum += i;
        }

        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> v;
        int p = 0;
        for(int x: nums) {
            p += x;
            v.push_back(x);
            if(p > sum - p){
                break;
            }
        }

        return v;
    }
};
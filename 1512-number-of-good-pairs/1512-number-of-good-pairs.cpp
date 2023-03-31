class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        int count = 0;
        for(auto n:nums){
           count += mp[n]++;
        }

        return count;
    }
};
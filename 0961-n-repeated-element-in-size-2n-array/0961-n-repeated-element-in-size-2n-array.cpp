class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        int m = n/2;

        map<int,int> mp;
        for(auto x: nums){
            mp[x]++;
        }

        for(auto x: mp){
            if(x.second == m){
                return x.first;
            }
        }

        return 0;
    }
};
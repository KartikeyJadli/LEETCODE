class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int,int> mp;
        vector<int> v;
        int n = nums.size();

        for(auto x: nums){
            for(auto y: x){
                mp[y]++;
            }
        }

        for(auto x: mp){
            if(x.second == n){
                v.push_back(x.first);
            }
        }

        return v;
    }
};
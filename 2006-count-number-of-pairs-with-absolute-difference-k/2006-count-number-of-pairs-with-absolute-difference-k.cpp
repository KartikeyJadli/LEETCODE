class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size(),count = 0;
        // map<int,int> mp;

        // for(auto x: nums){
        //     mp[x]++;
        // }

        // for(auto it: nums){
        //     for(auto x: mp){
        //         if(mp.find(it + k) != mp.end()){
        //             count += x.second;
        //         }
        //     }
        // }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(nums[i] + k == nums[j]){
                    count++;
                }
            }
        }

        return count;
    }
};
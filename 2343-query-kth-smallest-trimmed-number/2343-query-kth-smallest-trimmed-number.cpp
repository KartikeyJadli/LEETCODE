class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int i,n = nums.size();
        vector<int> v;
        for(auto it:queries){
            vector<pair<string,int>> v1;
            int y = nums[0].size();
            for(i=0;i<n;i++){
                string s = nums[i];
                v1.push_back({s.substr(y-it[1]),i});
            }

            sort(v1.begin(),v1.end());
            v.push_back(v1[it[0]-1].second);
        }

        return v;
    }
};
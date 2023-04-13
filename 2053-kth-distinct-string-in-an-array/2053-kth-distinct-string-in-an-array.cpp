class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        vector<string> v;
        int n = arr.size();
        unordered_map<string,int> mp;
        for(auto x: arr){
            mp[x]++;
        }

        for(int i=0;i<n;i++){
            if(mp[arr[i]] == 1){
                v.push_back(arr[i]);
            }
        }

        return v.size() < k ? "" : v[k-1];
    }
};
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr2.size();
        vector<int> v;
        map<int,int> mp;

        for(auto x: arr1){
            mp[x]++;
        }

        for(int i=0;i<n;i++){
            for(auto x: mp){
                if(x.first == arr2[i]){
                    for(int j=0;j<x.second;j++){
                        v.push_back(x.first);
                    }
                    mp.erase(x.first);
                }
            }
        }

        for(auto x: mp){
            if(x.second > 0){
                for(int j=0;j<x.second;j++){
                    v.push_back(x.first);
                }
            }
        }

        return v;
    }
};
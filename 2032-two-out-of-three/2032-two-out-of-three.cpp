class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        set<int> s;
        map<int,int> mp;
        for(auto i: nums1){
            if(s.find(i) != s.end());
            else{
                mp[i]++;
            }

            s.insert(i);
        }

        s.clear();
        for(auto i: nums2){
            if(s.find(i) != s.end());
            
            else{
                mp[i]++;
            }

            s.insert(i);
        }

        s.clear();
        for(auto i: nums3){
            if(s.find(i) != s.end());
            
            else{
                mp[i]++;
            }

            s.insert(i);
        }

        vector<int> v;
        for(auto i:mp){
            int x = i.second;
            if(x >= 2)
                v.push_back(i.first);
        }
        
        return v;
    }
};
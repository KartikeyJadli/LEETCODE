class Solution {
public:
    vector<int> partitionLabels(string s) {
        if(s.length() == 1){
            return {1};
        }

        unordered_map<char,int> mp;
        // Filling the characters and their occurences
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            mp[ch] = i;
        }
        // Creating the array with the partitions
        vector<int> v;
        int prev = -1;
        int maxi = 0;
        
        for(int i = 0; i < s.size(); i++){
            maxi = max(maxi, mp[s[i]]);
            if(maxi == i){
                // partition time
                v.push_back(maxi - prev);
                prev = maxi;
            }
        }
        
        return v;
    }
};
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        map<char,int> mp;
        for(auto x: s){
            mp[x]++;
        }

        int temp = mp[s[0]];
        for(auto x: mp){
            if(x.second != temp){
                return false;
            }
        }

        return true;
    }
};
class Solution {
public:
    int longestSubstring(string s, int k) {
        map<char,int> mp;
        for(auto x: s){
            mp[x]++;
        }

        int i = 0;

        while(i < s.size() && mp[s[i]] >= k){
            i++;
        }

        if(i == s.size()){
            return i;
        }

        int mx1 = longestSubstring(s.substr(0,i),k);
        int mx2 = longestSubstring(s.substr(i+1,s.size()),k);

        return max(mx1,mx2);
    }
};
class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        map<char,int> mp;
        int count = 0;

        for(int i=n-1;i>=0;i--) {
            int maxi = INT_MIN;
            for(char ch='a';ch<='z';ch++) {
                if(mp[ch] != 0 && abs(s[i] - ch) <= k) {
                    maxi = max(maxi , mp[ch]);
                }
            }

            if(maxi == INT_MIN){ 
                mp[s[i]] = 1;
            }

            else{
                mp[s[i]] = maxi + 1;
            }
            count = max(count,mp[s[i]]);
        }

        return count;
    }
};
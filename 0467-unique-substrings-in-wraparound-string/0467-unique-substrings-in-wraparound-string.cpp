class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int count = 1,ans = 1,n = s.size();
        vector<int> freq(26,0);
        freq[s[0] - 'a'] = 1;
        for(int i=1;i<n;i++){
            if ((s[i-1] - 'a' + 1) % 26 == s[i] - 'a'){
                ans++;
            }

            else{
                ans = 1;
            }

            if (freq[s[i] - 'a'] < ans){
                count += ans - freq[s[i] - 'a'];
                freq[s[i] - 'a'] = ans;
            }
        }

        return count;
    }
};
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector <int> v(26);
        int low = 0,count = 0, mx = 0, diff;

        for (int i=0;i<s.length();i++) {
            int c = s[i] - 'A';
            v[c]++;
            count = max(count, v[c]);
            diff = (i - low + 1) - count;
            
            if (diff > k) {
                v[s[low] - 'A']--;
                low++;
            }
            
            mx = max(mx, (i - low + 1));
        }
        
        return mx;
    }
};
class Solution {
public:
    int countHomogenous(string s) {
        int n = s.length(),i = 0,mod = 1e9 + 7;
        long long count = 0;

        while(i < n){
            int j = i;
            while(j+1 < n && s[j+1] == s[i]){
                j++;
            }

            long long temp = j - i + 1;
            count += temp * (temp + 1)/2;
            i = j + 1;
        }

        return count % mod;
    }
};
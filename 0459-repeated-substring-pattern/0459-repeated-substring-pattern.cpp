class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        vector<int> v(n);

        int i = 1,j = 0;

        while(i < n){
            if(s[i] == s[j]){
                v[i] = j + 1;
                i++;
                j++;
            }

            else{
                if(j > 0){
                    j = v[j-1];
                }

                else{
                    v[i] = 0;
                    i++;
                }
            }
        }
        
        return v[n-1] && n % (n - v[n-1]) == 0;
    }
};
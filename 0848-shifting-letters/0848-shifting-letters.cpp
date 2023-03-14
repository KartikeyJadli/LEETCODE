class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.length(),j = 0;

        for(int i=n-1;i>=0;i--){
            j = (j + shifts[i]) % 26;
            s[i] = ((s[i] + j) - 'a') % 26 + 'a';
        }

        return s;
    }
};
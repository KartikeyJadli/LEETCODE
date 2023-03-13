class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> v(m+1, vector<int>(n+1, 0));
        int numz,numo;

        for(auto &s : strs) {
            numz = numo = 0;
            for (auto c : s) {
                if(c == '0'){
                    numz++;
                }
                
                else if(c == '1'){
                    numo++;
                }
            }

            for(int i=m;i>=numz;i--) {
                for(int j=n;j>=numo;j--) {
                    v[i][j] = max(v[i][j],v[i - numz][j - numo] + 1);
                }
            }
        }

        return v[m][n];
    }
};
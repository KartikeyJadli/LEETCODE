class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        vector<vector<int>> v(2, vector<int>(2, 0));

        for(int i=0; i<n; i++){
            v[s[i]-'0'][i%2]++;
        }

        int count = v[1][0] + v[0][1];
        count = min(count,v[0][0] + v[1][1]);
        for(int i=0; i<n; i++){
            v[s[i]-'0'][i%2]--;
            v[s[i]-'0'][(n+i)%2]++;
            count = min(count,v[1][0] + v[0][1]);
            count = min(count,v[0][0] + v[1][1]);
        }

        return count;
    }
};
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length(),idx = -1;
        vector<int> v(n,INT_MAX);

        for(int i=0;i<n;i++){
            if(s[i] == c){
                idx = i;
            }

            v[i] = min(v[i],idx != -1 ? abs(i - idx) : INT_MAX);
        }

        for(int i=n-1;i>=0;i--){
            if(s[i] == c){
                idx = i;
            }

            v[i] = min(v[i],abs(i - idx));
        }

        return v;
    }
};
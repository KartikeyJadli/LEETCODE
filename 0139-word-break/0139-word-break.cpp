class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> v(n+1, 0);
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        v[n] = 1;
        for(int i=n-1;i>=0;i--){
            string str = "";
            for(int ind=i;ind<n;ind++){
                str.push_back(s[ind]);
                if(st.count(str) && v[ind+1]){
                    v[i] = 1;
					break;
				}
            }
        }

        return v[0];
    }
};
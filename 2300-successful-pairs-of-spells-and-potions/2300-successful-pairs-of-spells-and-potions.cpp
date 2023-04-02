class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long success) {
        sort(begin(p), end(p));
        int n = p.size();
        vector<int> ans(s.size());
        for(int i = 0; i <s.size(); i++){
            long long div = success / s[i];
            if(success % s[i] != 0) div++;
            ans[i] = n - (lower_bound(begin(p), end(p), div) - begin(p));
        }
        
        return ans;
    }
};
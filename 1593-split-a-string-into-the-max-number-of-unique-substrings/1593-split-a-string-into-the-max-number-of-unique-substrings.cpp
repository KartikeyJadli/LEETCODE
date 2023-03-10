class Solution {
    public:
    size_t ans;
    void backtrack(const string& s,size_t offs,unordered_set<string>& st){
        if (offs == s.size()){
            ans = max(ans,st.size());
            return;
        }
        
        if (st.size() + s.size() - offs <= ans){
            return;
        }

        for (size_t i = 1; i + offs <= s.size() && st.size() + 1 + (s.size() - offs + i - 1) > ans;i++){
            auto part = s.substr(offs, i);
            if (st.count(part)){
                continue;
            }

            st.insert(part);
            backtrack(s, offs + i, st);
            st.erase(part);
        }
    }
    
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        ans = 0;     
        backtrack(s,0,st);
        
        return ans;
    }
};
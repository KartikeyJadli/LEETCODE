class Solution {
public:
    char repeatedCharacter(string s) {
        int n = s.length();
        set<char> st;
        st.insert(s[0]);
        for(int i=1;i<n;i++){
            auto pos = st.find(s[i]);
            if(*pos == s[i]){
                return s[i];
            }

            st.insert(s[i]);
        }

        return 'a';
    }
};
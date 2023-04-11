class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        int n = s.length();

        for(int i=0;i<n;i++){
            if(s[i] == '*'){
                st.pop();
            }

            else{
                st.push(s[i]);
            }
        }

        n = st.size() - 1;
        string str(st.size(),'*');
        while(!st.empty()){
            str[n--] = st.top();
            st.pop();
        }

        return str;
    }
};
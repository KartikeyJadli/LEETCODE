class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        int ind = 0,n = s.length();
        string str = "";

        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
                ind = i;
            }

            else{
                if(st.top() == '(' && s[i] == ')'){
                    st.pop();
                }

                else{
                    st.push(s[i]);
                }

                if(st.empty()){
                    str += s.substr(ind+1,i - ind - 1);
                }
            }
        }

        return str;
    }
};
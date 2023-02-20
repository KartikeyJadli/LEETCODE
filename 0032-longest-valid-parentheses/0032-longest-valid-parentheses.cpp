class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        
        int count=0;
        st.push(-1);
        
        for(int i=0;i<s.length();i++){
        
            if(s[i]=='(')
                st.push(i);
            
            else if(s[i] == ')'){
                st.pop();
            
                if(st.empty()) 
                    st.push(i);
                
                else
                    count = max(count,i - st.top());
            }
        }
        
        return count;
    }
};
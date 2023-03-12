class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int count = 0,n = s.length();

        for(int i=0;i<n;i++){
            if(s[i] == '('){
                st.push(s[i]);
            }

            else{
                if((i + 1) < n && s[i] == s[i+1]){
                    i++;
                }

                else{
                    count++;
                }

                if(!st.empty()){
                    st.pop();
                }

                else{
                    count++;
                }
            }
        }

        return count + 2 * st.size();
    }
};
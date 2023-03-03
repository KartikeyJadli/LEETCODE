class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int n = s.length(),count = 0;
        
        for(int i=n-1;i>=0;i--){
            char ch = s[i];

            if(!st.empty() && st.top() < ch){
                count++;
                st.pop();
            }

            else{
                st.push(ch);
            }
        }

        return count;
    }
};
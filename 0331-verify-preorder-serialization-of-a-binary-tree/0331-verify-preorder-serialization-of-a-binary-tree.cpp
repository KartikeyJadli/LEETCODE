class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<int> st;
        int n = preorder.length(),top,i = 0;

        while(i < n){
            if(!isdigit(preorder[i]) && preorder[i] != '#'){
                return false;
            }

            if(st.size() != 0){
                top = st.top();
                st.pop();
                top--;
                st.push(top);

                while(st.size() && !st.top()){
                    st.pop();
                }
            }

            else if(i != 0){
                return false;
            }

            if(isdigit(preorder[i])){
                while(isdigit(preorder[i+1])){
                    i++;
                }

                st.push(2);
            }

            i += 2;
        }

        return st.size() == 0 ? true : false;
    }
};
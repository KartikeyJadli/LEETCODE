class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> v(temperatures.size());
        stack<int> st;

        for(int i=0;i<temperatures.size();i++){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                int pos = st.top();
                v[pos] = i - pos;
                st.pop();
            }

            st.push(i);
        }

        return v;
    }
};
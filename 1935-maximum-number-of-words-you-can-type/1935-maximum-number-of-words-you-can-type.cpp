class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        set<char> st;
        int n = text.size(),count = 0;
        vector<string> v;
        string str1;
        stringstream str(text);

        while(getline(str, str1, ' ')) { 
            v.push_back(str1);
        }
        
        for(auto x: brokenLetters){
            st.insert(x);
        }

        for(auto x: v){
            cout << x << " ";
        }

        n = v.size();
        count = n;
        for(int i=0;i<n;i++){
            string s = v[i];
            for(int j=0;j<s.size();j++){
                if(st.find(s[j]) != st.end()){
                    count--;
                    break;
                }
            }
        }

        return count;
    }
};
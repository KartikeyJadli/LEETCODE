class Solution {
public:
    string maskPII(string s) {
        string str;
        unordered_set<char> st = {'+', '-', '(', ')', ' '};

        if(st.find(s[0]) != st.end() || isdigit(s[0])) {
            string temp;
            for(auto c: s){
                if(isdigit(c)){
                    temp.push_back(c);
                }
            }

            if(temp.size() != 10) {
                str.push_back('+');
                for(size_t i=0; i!=temp.size() - 10;i++){
                    str.push_back('*');
                }

                str.push_back('-');
            }

            str += "***-***-";
            for(size_t i=temp.size()-4;i!=temp.size();i++){
                str.push_back(temp[i]);
            }
        }

        else{
            str.push_back(tolower(s[0]));
            str += "*****";
            for(size_t i=0;i!=s.size();i++)
                if (s[i] == '@') {
                    for(size_t j = i-1;j!=s.size();j++){
                        str.push_back(tolower(s[j]));
                    }
                    
                    break;
                }
        }
        
        return str;
    }
};
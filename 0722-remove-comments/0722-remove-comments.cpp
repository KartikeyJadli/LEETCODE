class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> v;
        string s;
        bool flag = false;
        for(int i = 0; i < source.size(); i++) {
            for(int j = 0; j < source[i].size(); j++) {
                if(!flag && j + 1 < source[i].size() && source[i][j] == '/' && source[i][j+1]=='/'){
                    break;
                }

                else if(!flag && j + 1 < source[i].size() && source[i][j] == '/' && source[i][j+1]=='*'){
                    flag = true;
                    j++;
                }
                
                else if(flag && j + 1 < source[i].size() && source[i][j] == '*' && source[i][j+1]=='/'){
                    flag = false;
                    j++;
                }
                
                else if(!flag){
                    s.push_back(source[i][j]);
                }
            }
            
            if(!flag && s.size()){
                v.push_back(s);
                s.clear();
            }
        }

        return v;
    }
};
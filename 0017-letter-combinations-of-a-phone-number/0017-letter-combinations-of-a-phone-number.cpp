class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> v {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}, vec;
        
        for(int i=0;i<digits.size();i++){
            int n = vec.size();
            
            for(int j=0;j<v[digits[i] - '0'].size();j++){
                string s = v[digits[i] - '0'];
                
                if(i == 0){
                    string str = "";
                    str = str + s[j];
                    vec.push_back(str);
                }
                
                else{
                    for(int k=0;k<n;k++){
                        if(j == 0)
                            vec[k] = vec[k] + s[j];
                        
                        else{
                            string str2 = vec[k];
                            str2.pop_back();
                            str2 += s[j];
                            vec.push_back(str2);
                        }
                    }
                }
            }
        }
        
        return vec;
    }
};
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string res = "";
        for (const auto& str : dictionary) {
            if (helper(s, str)) {
                if (str.size() > res.size()) {
                    res = str;
                }
                
                else if (str.size() == res.size() && str < res) {
                    res = str;
                }
            }
        }
        
        return res;
    }
    
    bool helper(string s, string d) {
        int index = 0;
        for (int i=0; i<s.size(); i++) {
            if (index < d.size() && s[i] == d[index]) {
                index++;
            }
        }
        return index == d.size() ? true : false;
    }
};
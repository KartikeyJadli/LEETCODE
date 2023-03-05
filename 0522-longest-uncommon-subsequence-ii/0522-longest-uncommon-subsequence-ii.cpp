class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        unordered_map<string,int> mp;

        for (auto& s: strs) {
            for (int i = 0; i < (1 << s.size()); i++) {
                string str;
                for (int j = 0; j < s.size(); j++) {
                    if ((i >> j) & 1) 
                        str += s[j];
                }

                mp[str]++ ;
            }
        }

        int count = -1;
        for (auto &x: mp) {
            if (x.second == 1) 
                count = max(count,(int)x.first.size()) ;
        }

        return count;
    }
};
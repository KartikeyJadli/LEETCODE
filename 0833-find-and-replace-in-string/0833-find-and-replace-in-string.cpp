class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        string str = "";
        int n = indices.size();
        map<int,pair<string, string>> mp;
        for (int i=0;i<n;i++) {
            mp[indices[i]] = {sources[i], targets[i]};
        }

        auto it = mp.begin();
        n = s.size();
        for (int i=0;i<n;i++) {
            if (i != it->first) {
                str.push_back(s[i]);
            }
            
            else {
                if(s.substr(it->first, it->second.first.size()) != it->second.first){
                    str.push_back(s[i]);
                }

                else{
                    str += it->second.second;
                    i += it->second.first.size() - 1;
                }

                it++;
            }
        }

        return str;
    }
};
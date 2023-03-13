class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> v;
        if(s.size() < 10){
            return v;
        }
        
        unordered_map<string,int> mp;
        for(int i=0; i<=s.size()-10;i++){ 
            mp[s.substr(i, 10)]++;
        }

        for(auto it=mp.begin(); it!=mp.end();it++){
            if(it->second > 1){
                v.push_back(it->first);
            }
        }

        return v;
    }
};
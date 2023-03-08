class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& a, string& b) { 
             return a.size() < b.size(); 
        });

        map<string, int> mp;
        int count = 1;
        for(int i=0;i<words.size();i++){
            int temp = 1;
            for(int j=0;j<words[i].size();j++){
                string str = words[i];
                str.erase(j, 1);
                if(mp.find(str) != mp.end()){
                    temp = max(temp, mp[str]+1);
                }
            }

            mp[words[i]] = temp;
            count = max(count,temp);
        }

        return count;
    }
};
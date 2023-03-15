class Solution {
public:
    int wordCount(vector<string> &startWords, vector<string> &targetWords) {
        int n = startWords.size(),m = targetWords.size();
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            sort(startWords[i].begin(),startWords[i].end());
            mp[startWords[i]]++;
        }

        for(int i=0;i<m;i++){
            sort(targetWords[i].begin(),targetWords[i].end());
        }

        int cnt = 0;
        for(int i=0;i<m;i++){
            int sz = targetWords[i].size();
            for(int j=0;j<sz;j++){
                string s = "";
                for(int k=0;k<sz;k++){
                    if(j == k){
                        continue;
                    }

                    s += targetWords[i][k];
                }

                if(mp[s]){
                    cnt++;
                    break;
                }
            }
        }
        
        return cnt;
    }
};
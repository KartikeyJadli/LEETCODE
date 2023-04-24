class Solution {
public:
    bool func(string &word1, string &word2){
        vector<int> v(26, 0);
        for(int i=0;i<word1.size();i++){
           v[word1[i]- 'a']++;
        }

        for(int i=0;i<word2.size();i++){
            int x = v[word2[i]-'a'];
            if(x == 0) return false;
        }

        return true;
    }

    int similarPairs(vector<string>& words) {
        sort(words.begin(), words.end());
        for(auto &i:words){
            sort(i.begin(), i.end());
        }

        int n = words.size();
        int cnt = 0;

        for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){ 
                if(func(words[i], words[j]) and func(words[j], words[i]))
                    cnt++;
            }
        }
        
        return cnt;
    }
};
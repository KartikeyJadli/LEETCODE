class Solution {
public:
    bool isConcatenated(string word, unordered_map<string,bool> &mp, bool WholeWord) {
        if(word.size() == 0){
            return WholeWord;
        }

        if(WholeWord && mp.count(word) > 0){
            return mp[word];
        }

        for (int i=1;i<word.size();i++) {
            if(mp.count(word.substr(0,i)) > 0 && mp[word.substr(0,i)]) {
                if (isConcatenated(word.substr(i),mp,true)) {
                    mp[word] = true;
                    return true;
                }
            } 
        }

        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_map<string,bool> mp;
        for (int i=0;i<words.size();i++) {
            mp[words[i]] = true;
        }
        
        vector<string> v;
        for (int i=0;i<words.size();i++) {
            if (isConcatenated(words[i],mp,false)){
                v.push_back(words[i]);
            }
        }

        return v;
    }
};
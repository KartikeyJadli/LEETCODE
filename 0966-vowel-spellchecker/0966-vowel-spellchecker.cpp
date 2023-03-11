class Solution {
public:
    struct TrieNode {
        vector<string> str;
        unordered_map<char,TrieNode*> next;
    };
    
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        TrieNode * origHead = new TrieNode;
        TrieNode * caseHead = new TrieNode;
        TrieNode * voweHead = new TrieNode;
        for (auto & word: wordlist) {
            TrieNode * origCurr = origHead;
            TrieNode * caseCurr = caseHead;
            TrieNode * voweCurr = voweHead;
            for (auto ch: word) {
                if(origCurr->next.find(ch) == origCurr->next.end())
                    origCurr->next.insert({ch, new TrieNode});
                origCurr = origCurr->next[ch];
                
                if(ch <= 'Z'){
                    ch += 32;
                }

                if (caseCurr->next.find(ch) == caseCurr->next.end())
                    caseCurr->next.insert({ch, new TrieNode});
                caseCurr = caseCurr->next[ch];
                
                if (vowels.find(ch) != vowels.end())
                    ch = '*';
                if (voweCurr->next.find(ch) == voweCurr->next.end())
                    voweCurr->next.insert({ch, new TrieNode});
                voweCurr = voweCurr->next[ch];
            }
            origCurr->str.push_back(word);
            caseCurr->str.push_back(word);
            voweCurr->str.push_back(word);
        }
        vector<string> ans;
        for (auto & q: queries) {
            TrieNode * origCurr = origHead;
            TrieNode * caseCurr = caseHead;
            TrieNode * voweCurr = voweHead;
            for (auto ch: q) {
                if (origCurr && origCurr->next.find(ch) != origCurr->next.end()) {
                    origCurr = origCurr->next[ch];
                } else {
                    origCurr = NULL;
                    // break;
                }
                
                if (ch <= 'Z')
                    ch += 32;
                if (caseCurr && caseCurr->next.find(ch) != caseCurr->next.end()) {
                    caseCurr = caseCurr->next[ch];
                } else {
                    caseCurr = NULL;
                    // break;
                }
                
                if (vowels.find(ch) != vowels.end())
                    ch = '*';
                if (voweCurr && voweCurr->next.find(ch) != voweCurr->next.end()) {
                    voweCurr = voweCurr->next[ch];
                } else {
                    voweCurr = NULL;
                    // break;
                }
            }
            if (origCurr && origCurr->str.size() != 0)
                ans.push_back(origCurr->str[0]);
            else if (caseCurr && caseCurr->str.size() != 0)
                ans.push_back(caseCurr->str[0]);
            else if (voweCurr && voweCurr->str.size() != 0)
                ans.push_back(voweCurr->str[0]);
            else
                ans.push_back("");
        }
        return ans;
    }
};
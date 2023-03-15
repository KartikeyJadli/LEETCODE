class WordDictionary {
public:
    class Trie{
        public:
        bool isword;
        Trie *child[26];

        Trie(){
            isword = false;
            for(int i=0;i<26;i++){
                child[i] = NULL;
            }
        }
    };

    Trie *root = new Trie();
    WordDictionary() {}
    
    void addWord(string word) {
        Trie *temp = root;
        for(auto x: word){
            if(!temp->child[x - 'a']){
                temp->child[x - 'a'] = new Trie();
            }

            temp = temp->child[x - 'a'];
        }

        temp->isword = true;
    }
    
    bool search(string word) {
        return search(word.c_str(),root);
    }

    bool search(const char* word,Trie* ptr){
         for (int i = 0; word[i] && ptr;i++) {
            if (word[i] != '.') {
                ptr = ptr->child[word[i] - 'a'];
            } 
            
            else {
                Trie* tmp = ptr;
                for (int j=0;j<26; j++) {
                    ptr = tmp->child[j];
                    if(search(word + i + 1, ptr)) {
                        return true;
                    }
                }
            }
        }

        return ptr && ptr->isword;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
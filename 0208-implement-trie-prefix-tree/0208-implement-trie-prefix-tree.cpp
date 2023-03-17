class Trie {
public:
    struct Trienode{
        Trienode *child[26];
        bool isword;
    };
    Trienode *trie;
    Trie() {
        trie = new Trienode();
    }
    
    void insert(string word) {
        Trienode *ptr = trie;
        for(int i=0;i<word.length();i++){
            if(!ptr->child[word[i] - 'a']){
                ptr->child[word[i] - 'a'] = new Trienode();
            }
            
            ptr = ptr->child[word[i] - 'a'];
        }
        
        ptr->isword = true;
    }
    
    bool search(string word) {
        Trienode *ptr = trie;
        for(int i=0;i<word.length();i++){
            if(!ptr->child[word[i] - 'a']){
                return false;
            }
            ptr = ptr->child[word[i] - 'a'];
        }
        
        return ptr->isword;
    }
    
    bool startsWith(string prefix) {
        Trienode *ptr = trie;
        for(int i=0;i<prefix.length();i++){
            if(!ptr->child[prefix[i] - 'a']){
                return false;
            }
            
            ptr = ptr->child[prefix[i] - 'a'];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
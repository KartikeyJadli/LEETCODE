class MagicDictionary {
public:
    class Trie{
        public:
        char ch;
        vector<Trie*> v;
        bool word;

        Trie(char ch,bool word){
            this->ch = ch;
            v.assign(26,nullptr);
            this->word = word;
        }

        Trie *get(char ch){
            int i = ch - 'a';
            if(v[i] == nullptr){
                Trie *temp = new Trie(ch,false);
                v[i] = temp;
                return temp;
            }

            return v[i];
        }
    };

    Trie *root;

    MagicDictionary() {
        root = new Trie(' ',false);
    }
    
    void buildDict(vector<string> dictionary) {
        int n = dictionary.size();
        for(int i=0;i<n;i++){
            Trie *temp = root;
            for(int j=0;j<dictionary[i].length();j++){
                Trie *ptr = temp->get(dictionary[i][j]);
                temp = ptr;
            }

            temp->word = true;
        }
    }
    
    bool search(string searchWord) {
        int n = searchWord.length();
        if(n == 0){
            return false;
        }

        for(int i=0;i<root->v.size();i++){
            if(DFS(searchWord,0,false,root->v[i],root)){
                return true;
            }
        }

        return false;
    }

    bool DFS(string &str,int i,bool change,Trie *node,Trie *t){
        int n = str.length();
        if(i == n){
            return change && t->word;
        }

        if(node == nullptr || (node->ch != str[i] && change)){
            return false;
        }

        if(str[i] != node->ch){
            change = true;
        }

        for(int j=0;j<node->v.size();j++){
            if(DFS(str,i+1,change,node->v[j],node))
                return true;
        }
    
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
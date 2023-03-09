class MapSum {
public:
    struct Trie{
        Trie *child[26];
        int sum;

        Trie(){
            sum = 0;
            for(int i=0;i<26;i++){
                child[i] = NULL;
            }
        }
    };

    Trie *root;
    map<string,int> mp;
    
    MapSum() {
        root = new Trie();
    }
    
    void insert(string key, int val) {
        int diff = val - mp[key];
        Trie *temp = root;
        for(auto x: key){
            x = x - 'a';
            if(temp->child[x] == NULL){
                temp->child[x] = new Trie();
            }

            temp = temp->child[x];
            temp->sum += diff;
        }

        mp[key] = val;
    }
    
    int sum(string prefix) {
        Trie *temp = root;
        for(auto x: prefix){
            x = x - 'a';
            if(temp->child[x] == NULL){
                return 0;
            }

            temp = temp->child[x];
        }

        return temp->sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
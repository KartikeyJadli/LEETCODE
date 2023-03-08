class Solution {
public:
    
    struct trie{
        trie* child[26];
        bool isend;
        
        trie(){
            isend = false;
            for(int i=0;i<26;i++){
                child[i]=nullptr;
            }
        }
    };
    
    trie* root= new trie();
    
    void insert(string& word){
        trie* temp = root;
        for(auto& letter: word){
            int idx = letter - 'a';
            
            if(temp->child[idx] == nullptr){
                temp->child[idx] = new trie();
            }
            
            temp = temp->child[idx]; 
        }
        
        temp->isend = true;
    }
    
    void dfs(trie* root,string temp,string &str){
        for(int i=0;i<26;i++){
            if(root->child[i] != nullptr && root->child[i]->isend == true){
                cout << temp << endl;
                temp += char(i + 'a');
                if(temp.size() > str.size()){
                    str = temp;
                }
                
                else if(temp.size() == str.size() && str > temp){
                    str = temp;
                }

                dfs(root->child[i],temp,str);
                temp.pop_back();
            }
        }
        
    }
    
    string longestWord(vector<string>& words) {
        string str = "";

        for(auto word:words){
            insert(word);
        }

        dfs(root,"",str);

        return str;
    }
};
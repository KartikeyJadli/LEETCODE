class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<int> v(26,-1);
        int n = key.length(),m = message.length();
        
        for(int i=0,k=0;i<n;i++){
            if(key[i] != ' ' && v[key[i] - 'a'] == -1){
                v[key[i] - 'a'] = k++;
            }
        }
        
        for(int i=0;i<m;i++){
            if(message[i] != ' '){
                message[i] = v[message[i] - 'a'] + 'a';
            }
        }
        
        return message;
    }
};
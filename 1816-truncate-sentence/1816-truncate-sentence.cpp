class Solution {
public:
    string truncateSentence(string s, int k) {
        string str = "";
        int n = s.length();
        
        for(int i=0;i<n;i++){
            if(s[i] == ' '){
                if(k == 1){
                    break;
                }
                
                k--;
                str += s[i];
            }
            
            else{
                str += s[i];
            }
        }
        
        return str;
    }
};
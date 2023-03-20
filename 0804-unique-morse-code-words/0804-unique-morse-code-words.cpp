class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> v = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        string str = "";
        set<string> s;
        
        for(int i=0;i<words.size();i++){
            str = "";
            for(int j=0;j<words[i].length();j++){
                str += v[words[i][j] - 'a'];
            }
            
            s.insert(str);
        }
        
        return s.size();
    }
};
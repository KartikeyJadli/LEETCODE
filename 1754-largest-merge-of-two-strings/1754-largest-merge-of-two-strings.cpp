class Solution {
public:
    string largestMerge(string word1, string word2) {
        string str;
        int i = 0, j = 0;
        while(i < word1.size() && j < word2.size()) {
            if(word1.compare(i,word1.size() - i,word2,j,word2.size() - j) > 0){
                str += word1[i++];
            }   
            
            else{
                str += word2[j++];
            }
        }
        
        return str + word1.substr(i) + word2.substr(j);
    }
};
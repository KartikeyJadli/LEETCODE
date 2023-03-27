class Solution {
public:
    string reversePrefix(string word, char ch) {
        string str = "";
        int n = word.length();

        if(word.find(ch) == -1){
            return word;
        }

        for(int i=0;i<n;i++){
            if(word[i] != ch){
                str += word[i];
            }

            else{
                str += word[i];
                break;
            }
        }

        int j = 0;
        for(int i=str.length()-1;i>=0;i--){
            word[j] = str[i];
            j++;
        }

        return word;
    }
};
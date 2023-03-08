class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.length();
        int count = 0,temp = 0;
        map<char,int> mp;
        mp[word[0]]++;

        for(int i=1;i<n;i++){
            if(word[i-1] > word[i]){
                temp = i;
                mp.clear();
            }

            mp[word[i]]++;

            if(mp.size() >= 5){
                if(i - temp + 1 > count){
                    count = i - temp + 1;
                }
            }
        }

        return count;
    }
};
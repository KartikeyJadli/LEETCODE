class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        map<string,int> mp1,mp2;
        int count = 0;

        for(auto x: words1){
            mp1[x]++;
        }

        for(auto y: words2){
            mp2[y]++;
        }

        for(auto [x,y]: mp1){
            if(y == 1 && mp2[x] == 1){
                count++;
            }
        }

        return count;
    }
};
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int n = words.size();
        vector<int> v(26);
        int count = 0;
        
        for(auto x: chars){
            v[x - 'a']++;
        }

        for(auto x: words){
            vector<int> v1(26);
            bool flag = true;

            for(auto y: x){
                auto in = y - 'a';
                if(++v1[in] > v[in]){
                    flag = false;
                    break;
                }
            }

            if(flag){
                count += x.size();
            }
        }

        return count;
    }
};
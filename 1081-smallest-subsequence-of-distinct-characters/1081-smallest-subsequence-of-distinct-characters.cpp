class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> v1(26,0),v2(26,0);
        string str = "";
        for(auto x: s){
            v1[x - 'a']++;
        }

        for(auto x: s){
            v1[x - 'a']--;
            if(v2[x - 'a']++ > 0){
                continue;
            }

            while(!str.empty() && str.back() > x && v1[str.back() - 'a'] > 0){
                v2[str.back() - 'a'] = 0;
                str.pop_back();
            }

            str += x;
        }

        return str;
    }
};
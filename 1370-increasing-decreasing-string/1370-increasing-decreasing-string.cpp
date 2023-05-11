class Solution {
public:
    string sortString(string s) {
        string str = "";
        vector<int> v(26,0);
        int n = s.length();
        for(auto x: s){
            v[x - 'a']++;
        }

        while(n--){
            for(int i=0;i<26;i++){
                if(v[i] > 0){
                    str += (i + 'a');
                    v[i]--;
                }
            }

            for(int i=25;i>=0;i--){
                if(v[i] > 0){
                    str += (i + 'a');
                    v[i]--;
                }
            }
        }

        return str;
    }
};
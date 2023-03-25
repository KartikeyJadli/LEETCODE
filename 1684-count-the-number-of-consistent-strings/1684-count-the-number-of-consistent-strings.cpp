class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int n = words.size(),count = 0;
        map<char,int> mp;

        for(auto x: allowed){
            mp[x]++;
        }

        for(int i=0;i<n;i++){
            string str = words[i];
            bool flag = true;
            for(int j=0;j<str.length();j++){
                if(mp.find(str[j]) == mp.end()){
                    flag = false;
                    break;
                }
            }

            if(flag){
                count++;
            }
        }

        return count;
    }
};
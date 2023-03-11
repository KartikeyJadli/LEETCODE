class Solution {
public:
    string originalDigits(string s) {
        vector<string> v = {"zero","two","four","six","eight","one","three","five","seven","nine"};
        vector<int> num = {0,2,4,6,8,1,3,5,7,9};
        vector<int> ch = {'z','w','u','x','g','o','r','f','v','i'};
        vector<int> freq(26,0);
        string str = "";

        for(auto x: s){
            freq[x - 'a']++;
        }

        for(int i=0;i<10;i++){
            int count = freq[ch[i] - 'a'];
            for(int j=0;j<v[i].size();j++){
                freq[v[i][j] - 'a'] -= count;
            }

            while(count--){
                str += to_string(num[i]);
            }
        }

        sort(str.begin(),str.end());
        return str;
    }
};
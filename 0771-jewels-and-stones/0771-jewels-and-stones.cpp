class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char,int> mp;

        for(auto x: stones){
            mp[x]++;
        }

        for(auto x: mp){
            cout << x.first << " " << x.second << endl;
        }

        int n = jewels.size();
        int count = 0;
        for(int i=0;i<n;i++){
            if(mp.find(jewels[i]) != mp.end()){
                cout << count << endl;
                count += mp[jewels[i]];
            }
        }

        return count;
    }
};
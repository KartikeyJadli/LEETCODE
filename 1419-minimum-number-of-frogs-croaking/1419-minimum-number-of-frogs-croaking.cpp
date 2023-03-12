class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        char ch[5] = {'c','r','o','a','k'};
        vector<int> v(5,0);
        int count = 0,frogs = 0;

        for(auto x: croakOfFrogs){
            auto it = find(ch,ch+5,x) - ch;
            if(it == 0){
                frogs++;
                v[it]++;
                continue;
            }

            if(v[it-1]-- <= 0){
                return -1;
            }

            if(it == 4){
                count = max(count,frogs--);
            }

            else{
                v[it]++;
            }
        }

        if(frogs > 0){
            return -1;
        }

        return count;
    }
};
class Solution {
public:
    bool judgeCircle(string moves) {
        pair<int,int> pa = {0,0};

        for(auto x: moves){
            if(x == 'U'){
                pa.second++;
            }

            else if(x == 'D'){
                pa.second--;
            }

            else if(x == 'R'){
                pa.first++;
            }

            else{
                pa.first--;
            }
        }

        return !pa.second && !pa.first;
    }
};
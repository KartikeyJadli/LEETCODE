class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int mxcount = 0;

        for(auto x: sentences){
            mxcount = max(mxcount,(int)count(x.begin(),x.end(),' '));
        }

        return mxcount + 1;
    }
};
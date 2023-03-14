class Solution {
public:
    int maxRepOpt1(string text) {
        map<char,vector<int>> mp;
        int n = text.size();
        for(int i=0;i<n;i++){
            mp[text[i]].push_back(i);
        }

        int count = 0;
        for(auto x: mp){
            int temp = 0,ptr = 1;
            int sum = 0;
            for(int i=0;i<x.second.size()-1;i++){
                if(x.second[i+1] - x.second[i] <= 1){
                    ptr++;
                }

                else{
                    if(x.second[i+1] - x.second[i] == 2){
                        temp = ptr;
                    }

                    else{
                        temp = 0;
                    }

                    ptr = 1;
                }
                sum = max(sum,temp + ptr);
            }

            if(sum < x.second.size()){
                sum++;
            }

            count = max(count,sum);
        }

        return count;
    }
};
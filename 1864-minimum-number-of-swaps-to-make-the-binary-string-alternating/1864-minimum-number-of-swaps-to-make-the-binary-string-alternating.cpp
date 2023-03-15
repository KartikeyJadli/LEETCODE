class Solution {
public:
    int minSwaps(string s) {
        int n = s.length();
        int countz[2] = {},counto[2] = {};

        for(int i=0,f=0;i<n;i++,f^=1){
            if(s[i] == '0'){
                if(f){
                    countz[0]++;
                }

                else{
                    countz[1]++;
                }
            }

            else{
                if(f){
                    counto[1]++;
                }

                else{
                    counto[0]++;
                }
            }
        }

        if(countz[0] == counto[0] && countz[1] == counto[1]){
            return min(countz[0],countz[1]);
        }

        else if(countz[0] == counto[0]){
            return countz[0];
        }

        else if(countz[1] == counto[1]){
            return countz[1];
        }

        else{
            return -1;
        }
    }
};
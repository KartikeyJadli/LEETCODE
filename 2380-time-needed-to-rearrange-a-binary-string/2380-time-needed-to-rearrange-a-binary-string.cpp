class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int count = 0;
        int flag = 0,n = s.length();

        while(true){
            flag = 0;
            for(int i=0;i<n;i++){
                if(s[i] == '0' && s[i+1] == '1'){
                    s[i] = '1';
                    s[i+1] = '0';
                    flag = 1;
                    i++;
                }
            }

            if(flag == 0){
                break;
            }

            count++;
        }

        return count;
    }
};
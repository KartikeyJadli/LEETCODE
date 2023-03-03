class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int count = 0,ud = 0;

        for(int i=0;i<bank.size();i++){
            string str = bank[i];
            int temp = 0;
            for(int j=0;j<str.length();j++){
                if(str[j] == '1'){
                    temp++;
                }
            }

            if(temp > 0){
                count += (temp * ud);
                ud = temp; 
            }
        }

        return count;
    }
};
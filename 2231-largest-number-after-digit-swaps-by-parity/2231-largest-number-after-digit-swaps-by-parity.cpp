class Solution {
public:
    int largestInteger(int num) {
        string str = to_string(num);

        for(int i=0;i<str.size();i++){
            for(int j=i+1;j<str.size();j++){
                if(str[i] < str[j] && ((str[i] - '0') % 2 == (str[j] - '0') % 2)){
                    swap(str[i],str[j]);
                }
            }
        }

        return stoi(str);
    }
};
class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int maxValue=0;
        int maxi=0;
        for(int i=0;i<strs.size();i++){
            bool c=false;
            int start=0;
            int end=strs[i].length()-1;
            while(start<=end){
                if(isalpha(strs[i][start])){
                    c=true;
                }
                
                start++;
            }
                if(!c){
                    int n=stoi(strs[i]);
                    maxValue=max(maxValue,n);
                }else{
                    int n=strs[i].length();
                    maxValue=max(maxValue,n);
                }
        }
        return maxValue;
        
    }
};
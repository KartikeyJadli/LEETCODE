class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0,count1 = 0,n = s.length();
        for(int i=0;i<n;i++){
            if(s[i] == 'L'){
                count1++;
            }
            
            else{
                count1--;
            }
            
            if(count1 == 0){
                count++;
            }
        }
        
        return count;
    }
};
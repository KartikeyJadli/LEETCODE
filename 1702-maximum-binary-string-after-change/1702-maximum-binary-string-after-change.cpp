class Solution {
public:
    string maximumBinaryString(string binary) {
        int i = 0, j = 0;
        int n = binary.length();
        while(i < n - 1){
            if(binary[i] == '1'){
                i++;
            }
            
            else{
                if(binary[i + 1] == '0') {
                    binary[i++] = '1';
                } 
                
                else {
                    j = max(j, i + 1);
                    
                    while(j < n && binary[j] == '1'){
                        j++;
                    }
                    
                    if(j == n){
                        return binary;
                    }
                    
                    swap(binary[i + 1], binary[j]);
                }
            }
        }

        return binary;
    }
};
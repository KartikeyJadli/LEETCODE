class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 0;
        int sum = 0;
        
        for(int i=n-1; i>=0; i--){
            
            if(i == n-1) {
                sum = digits[i] + 1;
            }
            
            else{
                sum = digits[i] + carry;
            }
            
            digits[i] = sum % 10;        
            carry = sum / 10;
        }
        
        if(carry > 0){
            digits.insert(digits.begin(), carry);
        }
        
        return digits;
    }
};
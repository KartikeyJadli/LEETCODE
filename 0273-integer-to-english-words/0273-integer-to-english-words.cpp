class Solution {
public:
     string ones[20] = {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten",  "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    
    
    string tens[10] = {"","", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty",                        "Ninety"};
    
    string helper(int num){
        
        if(num >= 1000000000){
            return helper(num/1000000000) + " Billion" + helper(num%1000000000);
        } 
        
        else if(num >= 1000000){
            return helper(num/1000000) + " Million" + helper(num%1000000);
        } 
        
        else if(num >= 1000){
            return helper(num/1000) + " Thousand" + helper(num%1000);
        } 
        
        else if(num >= 100){
            return helper(num/100) + " Hundred" + helper(num%100);
        } 
        
        else if(num >= 20){
            return " " + tens[num/10] + helper(num%10);
        } 
        
        else{ 
            return (ones[num]!="") ?  " " + ones[num] : "";
        }
        
        return "";
    }
    
    string numberToWords(int num) {
        if(num == 0) 
            return "Zero";
        
        string ans = helper(num);
        
        return ans.substr(1);
    }
};
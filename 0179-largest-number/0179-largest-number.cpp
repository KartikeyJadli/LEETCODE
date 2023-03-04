class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string s = "";
        
        sort(nums.begin(),nums.end(), comparenumber);
        for(int i=0;i<nums.size();i++){
            s = s + to_string(nums[i]);
        }
        
        if(s[0] == '0'){
            return "0";
        }
        
        else{
            return s;
        }
    }
    
     static bool comparenumber(int x,int y){
        string s1 = to_string(x) + to_string(y);
        string s2 = to_string(y) + to_string(x);
        
        return s1 > s2;
    }
};
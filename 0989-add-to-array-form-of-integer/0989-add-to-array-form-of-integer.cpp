class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
//         int n = num.size();
//         int r = 0,sum = 0;
        
//         for(int i=0;i<n;i++){
//             sum = sum * 10 + num[i];
//         }
//         int sum2 = sum + k;
//         int rem = 0;
//         // vector<int> v;
//         int i = 0;
//         while(sum2 > 0){
//             rem = sum2%10;
//             num[i] = rem;
//             sum2 = sum2/10;
//             i++;
//         }
//         // return v;
//         reverse(num.begin(),num.end());
        
//         return num;
        
        reverse(num.begin(),num.end());
        int n = num.size();
        
        for(int i=0;i<n;i++){
            num[i] = num[i] + k;
            k = num[i] + k;
            k = num[i]/10;
            num[i] = num[i]%10;
        }
        
        while(k){
            num.push_back(k%10);
            k = k/10;
        }
        
        reverse(num.begin(),num.end());
        
        return num;
    }
};
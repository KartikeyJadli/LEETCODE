class Solution {
public:
    string multiply(string num1, string num2) {
        string str;
        int n1 = num1.size(), n2 = num2.size();
        vector<int> v(n1 + n2, 0);
        int carray = 0;
        int k = n1 + n2 - 2;
        
        for (int i = 0; i < n1; i++){
            for (int j = 0; j < n2; j++){
                v[k - i - j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        
        for (int i = 0; i < v.size(); ++i){
            v[i] += carray;
            carray = v[i] / 10;
            v[i] = v[i] % 10;
        }

        k = v.size() - 1;
        while (k >= 0 && v[k] == 0) 
            k--;
        
        if (k < 0)
            return "0";   
        
        for (int i = k; i >= 0; i--)
            str.push_back(v[i]  + '0');
            
        return str;
    }
};
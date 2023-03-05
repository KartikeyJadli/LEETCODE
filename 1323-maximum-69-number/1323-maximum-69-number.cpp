class Solution {
public:
    int maximum69Number (int num) {
        auto s = to_string(num);
        auto i = find_if(s.begin(), s.end(), [](auto c) { 
            return c == '6'; 
        });
        
        if (i != s.end()){ 
            *i = '9';
        }

        return stoi(s);
    }
};
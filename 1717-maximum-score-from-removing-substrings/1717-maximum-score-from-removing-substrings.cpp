class Solution {
public:
    string usingstack(string s, char a, char b) {
        string st;
        for (auto ch : s) {
            if (!st.empty() && st.back() == a && ch == b) {
                st.pop_back();
            } 
            
            else{
                st.push_back(ch);
            }
        }
        
        return st;
    }
    
    int maximumGain(string s, int x, int y){
        char a = 'a',b = 'b';
        if (y > x) {
            swap(x,y);
            swap(a,b);
        }
        
        auto s1 = usingstack(s, a, b), s2 = usingstack(s1, b, a);
        
        return (s.size() - s1.size()) / 2 * x + (s1.size() - s2.size()) /2 * y;
    }
};
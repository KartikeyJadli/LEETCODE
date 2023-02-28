class Solution {
public:
    string sortSentence(string s) {
        istringstream iss(s);
        string word, ans;
        vector<string> v(9);
        while (iss >> word) {
            v[word.back() - '1'] = word.substr(0, word.size() - 1);
        }

        for (int i=0;i<9 && v[i].size();++i) { 
            if (i > 0){
                ans += " ";
            }

            ans += v[i];
        }

        return ans;
    }
};
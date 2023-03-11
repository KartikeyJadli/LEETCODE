class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> v(26);
        for (int i=0;i<s.length();i++) {
            v[s[i] - 'a'].push_back(i);
        }
        
        int result = 0;
        for(const string &word : words) {
            int indexes[26] = {0};
            int idx = 0;
            for (char ch : word) {
                int chIdx = (ch - 'a');
                const vector<int> &array = v[chIdx];
                if (indexes[chIdx] == array.size()) {
                    idx = -1;
                    break;
                }

                int low = indexes[chIdx], high = array.size() - 1;
                while (low < high) {
                    int mid = low + (high - low) / 2;
                    if (array[mid] < idx) {
                        low = low + 1;
                    }
                    
                    else {
                        high = mid;
                    }
                }

                if (array[low] < idx) {
                    idx = -1;
                    break;
                }
                
                else {
                    idx = array[low];
                    indexes[chIdx] = low + 1;
                }
            }

            if (idx >= 0) {
                result++;
            }
        }
        
        return result;
    }
};
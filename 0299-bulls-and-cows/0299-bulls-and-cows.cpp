class Solution {
public:
    string getHint(string secret, string guess) {
        map<char, int> mp;
        int n = secret.size(), a = 0, b = 0;
        for (int i=0;i<n;i++) {
            if (secret[i] == guess[i]) {
                a++;
                continue;
            }

            mp[secret[i]]++;
        }

        for (int i = 0; i < n; i++) {
            if (secret[i] != guess[i] && mp[guess[i]] > 0) {
                mp[guess[i]]--;
                b++;
            }
        }

        return to_string(a) + 'A' + to_string(b) + 'B';
    }
};
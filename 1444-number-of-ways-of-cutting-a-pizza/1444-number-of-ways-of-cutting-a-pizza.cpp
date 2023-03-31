class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int hl = pizza.size();
        int vl = pizza[0].size();

        vector<vector<bool>> flag(hl, vector<bool>(vl, false));
        for (int i = 0; i < hl; ++ i) {
            for (int j = 0; j < vl; ++ j) {
                if (pizza[i][j] == 'A') {
                    flag[i][j] = true;
                }
            }
        }
        return dfs(flag, k, 0 ,0, hl-1, vl-1);
    }

    int dfs(const vector<vector<bool>>& flag, int k, int left_h, int left_v, int right_h, int right_v) {
        string key = to_string(k) + "-" + to_string(left_h) + "-" + to_string(left_v);

        if (cache.find(key) != cache.end()) {
            return cache[key];
        }

        if (k == 1) {
            if (has_apple(flag, left_h, left_v, right_h, right_v)) {
                cache[key] = 1;
                return 1;
            } else {
                cache[key] = 0;
                return 0;
            }
        }

        if (!has_apple(flag, left_h, left_v, right_h, right_v)) {
            cache[key] = 0;
            return 0;
        }

        if (k > (right_h - left_h + right_v - left_v + 1)) {
            cache[key] = 0;
            return 0;
        }

        int res = 0;
        bool hs = false;
        for (int i = left_h; i < right_h; ++i) {
            if (!hs) {
                hs = has_apple(flag, left_h, left_v, i, right_v);
            }
            if (hs) {
                res += dfs(flag, k-1, i+1,  left_v, right_h, right_v);
                res %= root;
            }
        }

        bool vs = false;
        for (int j = left_v; j < right_v; ++ j) {
            if (!vs) {
                vs = has_apple(flag, left_h, left_v, right_h, j);
            }
            if (vs) {
                res += dfs(flag, k-1, left_h, j+1, right_h, right_v);
                res %= root;
            }
        }

        cache[key] = res;
        return res;
    }

    int has_apple(const vector<vector<bool>>& flag, int left_h, int left_v, int right_h, int right_v) {
        string key = to_string(left_h) + "-" + to_string(left_v) + "-" + to_string(right_h) + "-" + to_string(right_v);
        if (a_cache.find(key) != a_cache.end()) {
            return a_cache[key];
        }

        for (int i = left_h; i <= right_h; ++i) {
            for (int j = left_v; j <= right_v; ++j) {
                if (flag[i][j]) {
                    a_cache[key] = true;
                    return true;
                }
            }
        }
        a_cache[key] = false;
        return false;
    }

private:
    unordered_map<string, int> cache;
    unordered_map<string, bool> a_cache;
    int root = pow(10, 9) + 7;
};
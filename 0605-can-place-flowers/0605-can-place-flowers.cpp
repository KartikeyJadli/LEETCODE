class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0,m = flowerbed.size();
        for (int i=0;i<m;i++) {
            if(flowerbed[i] == 0 && (i - 1 < 0 || flowerbed[i - 1] != 1) && (i + 1 >= flowerbed.size() || flowerbed[i + 1] != 1)){
                flowerbed[i] = 1;
                cnt++;
            }

            if (cnt >= n){
                return true;
            }
        }

        return cnt >= n;
    }
};
class Solution {
public:
    bool mp[32*32*32] = {};
        bool isScramble(string &s1, string &s2,int start1, int end, int start2) {
        if(end == start1 + 1){ 
            return s1[start1] == s2[start2];
        }

        int stemp = (start1<<10) + (end<<5) + start2;
        if (mp[stemp]){  
            return false;
        }
          
        int a[26] = {0};

        for (int i=start1; i<end; i++)
            a[s1[i] - 'a']++;

        for (int i=start2; i<start2+end-start1; i++)
            if (a[s2[i] - 'a']-- == 0) {
                mp[stemp] = true; 
                return false;
            }

        for (int i=start1+1; i<end; i++){
            if (isScramble(s1, s2,start1,i,start2) && isScramble(s1, s2,i,end,start2+(i-start1))){
                mp[stemp] = true; 
                return true;
            }

            if (isScramble(s1, s2,start1,i,start2+(end-i)) && isScramble(s1, s2,i,end,start2 )){
                mp[stemp] = true; 
                return true;
            }
        }
        mp[stemp]=true;
        return false;
    }

    bool isScramble(string s1, string s2) {
        if(s1 == s2){
            return true;
        }

        int n = s1.length();
        return (isScramble(s1, s2,0,n,0));
    }
};
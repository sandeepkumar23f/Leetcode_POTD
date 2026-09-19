class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.length();
        if(n==1) return 1;
        int i=0,j=1;
        int maxlen=0;
        while(i<j && j<n){
            if(s[j]==s[j-1]+1){
                maxlen = max(maxlen,j-i+1);
                j++;
            }
            else {
                i=j;
                j++;
            }
        }
        return maxlen==0?1:maxlen;
    }
};
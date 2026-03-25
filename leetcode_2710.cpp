class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n = s.length();
        int val=0;
        int freq=0;
        for(char c: s){
            if(c==letter) freq++;
        }
        if(freq==0) return 0;
        return int(freq*100)/n;
    }
};
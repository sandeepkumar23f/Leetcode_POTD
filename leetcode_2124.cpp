
class Solution {
public:
    bool checkString(string s) {
        int n = s.length();
        int i=n-1;
        while(i>0){
            if(int(s[i-1])>s[i]) return false;
            i--;
        }
        return true;
    }
};
// here c-'A'+'a' finds the lower character of c.
// example: c=F then c-'A'+'a' equal to 71-65+97=103 and ascii value of f is 103

class Solution {
public:
    string greatestLetter(string s) {
        unordered_set<char> st(s.begin(),s.end());
        for(char c='Z'; c>='A'; c--){
            if(st.count(c) && st.count(c-'A'+'a')){
                return string(1,c);
            }
        }
        return "";
    }
};
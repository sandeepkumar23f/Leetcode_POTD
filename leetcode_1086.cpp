class Solution {
public:
    string convertToBin(int n){
        if(n==0) return "0";
        string result="";
        while(n>0){
            if(n%2==0) result = "0"+result;
            else result = "1"+result;
            n/=2;
        }
        return result;
    }
    bool queryString(string s, int n) {
        for(int i=1; i<=n; i++){
            string sub=convertToBin(i);
            if(s.find(sub) == string::npos) return false;
        }
        return true;
    }
};
class Solution {
public:
    string convertToBin(int n){
        if(n==0) return "0";
        string result="";
        while(n>0){
            if(n%2==0) result = "0" + result;
            else result = "1" + result;
            n/=2;        }
        return result;
    }
    int binaryGap(int n) {
        string s = convertToBin(n);
        int dist=0;
        int i=0,j=1;
        while(i<j && j<s.length()){
            if(s[i]=='1'){
                if(s[j]=='1'){
                    dist = max(dist,j-i);
                    i=j;
                }
                j++;
            }
            else{
                i++;
                j = i + 1;
            }
        }
        return dist;
    }
};
class Solution {
public:
    string addStrings(string s, string num2) {
        int i=s.size()-1;
        int j=num2.size()-1;
        int carry=0;
        string result="";
        while(i >= 0 || j >= 0 || carry){
            int sum=carry;
            if(i >= 0) sum += s[i--] - '0';
            if(j >= 0) sum += num2[j--] - '0';
            result += char('0'+(sum%10));
            carry=sum/10;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
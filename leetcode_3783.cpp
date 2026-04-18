class Solution {
public:
    int mirrorDistance(int n) {
        int temp=n;
        int ans=0;
        while(temp>0){
            ans = ans*10 + (temp%10);
            temp/=10;
        }
        return abs(n-ans);
    }
};
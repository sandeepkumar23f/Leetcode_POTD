class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mxE=INT_MIN;
        for(int x: nums){
            if(x>mxE) mxE=x;
        }
        int cnt=0;
        for(int x: nums){
            if(x!=mxE){
                cnt = cnt+(mxE-x);
            }
        }
        return cnt;
    }
};
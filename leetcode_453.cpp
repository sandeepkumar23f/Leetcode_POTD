class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        int minEl=INT_MAX;
        for(int x: nums) sum+=x;
        for(int x: nums){
            if(x<minEl) minEl=x;
        }
        return sum-n*minEl;
    }
};
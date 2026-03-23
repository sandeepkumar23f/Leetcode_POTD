class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        int maxval=INT_MIN;
        int maxidx=-1;
        for(int i=0; i<n; i++){
            if(nums[i]>maxval){
                maxval=nums[i];
                maxidx=i;
            }
        }
        // check whether the maxval is twice for every element in array
        for(int i=0; i<n; i++){
            if(i != maxidx && nums[i]*2>maxval) return -1;
        }
        return maxidx;
    }
};
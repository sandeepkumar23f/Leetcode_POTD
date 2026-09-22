class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int el: changed){
            mp[el]++;
        }
        
        vector<int> nums = changed;
        sort(nums.begin(),nums.end());

        for(int x: nums){
            if(mp[x]==0) continue;

            if(x==0){
                if(mp[x]<2) return {};
                ans.push_back(0);
                mp[0] -= 2;
            }
            else{
                if(mp[2*x]==0){
                    return {};
                }
                ans.push_back(x);
                mp[x]--;
                mp[2*x]--;
            }
        }
        return ans;
    }
};
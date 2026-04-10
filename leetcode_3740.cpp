class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
        int minDist=INT_MAX;
        for(auto &p:mp){
            vector<int> v=p.second;
            if(v.size()<3) continue;
            for(int i=0; i<v.size()-2; i++){
                int dist=2*(v[i+2]-v[i]);
                minDist=min(dist,minDist);
            }
        }
        return (minDist==INT_MAX)?-1:minDist;
    }
};
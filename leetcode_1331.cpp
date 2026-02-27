class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;               
        sort(temp.begin(), temp.end());       
        
        unordered_map<int, int> mp;           // value,rank
        int rank = 1;
        
        for(int num : temp){
            if(mp.find(num) == mp.end()){    
                mp[num] = rank++;
            }
        }
        
        vector<int> ans;
        for(int num : arr){
            ans.push_back(mp[num]);          
        }
        
        return ans;
    }
};
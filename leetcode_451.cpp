class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(char c: s){
            mp[c]++;
        }
        // we'll store the characters in the vector for the sorting
        vector<pair<char,int>> ans(mp.begin(),mp.end());

        sort(ans.begin(),ans.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });
        string result="";
        for(auto &p: ans){
            result += string(p.second,p.first);
        }
        return result;
    }
};
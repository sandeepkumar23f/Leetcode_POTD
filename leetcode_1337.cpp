class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        vector<pair<int,int>> strength;  // {soldier_count, row_index}
        
        for(int i = 0; i < rows; i++){
            int count = 0;
            for(int j = 0; j < cols; j++){
                if(mat[i][j] == 1) count++;
            }
            strength.push_back({count, i});
        }
        
        sort(strength.begin(), strength.end());
        
        vector<int> result;
        for(int i = 0; i < k; i++){
            result.push_back(strength[i].second);
        }
        
        return result;
    }
};
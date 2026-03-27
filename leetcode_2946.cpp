class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        k = k%n;
        vector<vector<int>> original=mat;
        
        for(int i=0; i<m; i++){
            // even row
            if(i%2==0){
                // left rotate by k times
                rotate(begin(mat[i]),begin(mat[i])+k,end(mat[i]));
            }
            // odd row
            else{
                // right rotate by k times
                rotate(mat[i].rbegin(),mat[i].rbegin()+k,mat[i].rend());
            }
        }
        return original==mat;
    }
};
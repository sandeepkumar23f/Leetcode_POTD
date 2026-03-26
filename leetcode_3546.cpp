class Solution {
public:
    typedef long long ll;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<ll> rowSum(m,0);
        vector<ll> colSum(n,0);
        ll total=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                total += grid[i][j];
                // row = i
                rowSum[i] += grid[i][j];
                // col = j
                colSum[j] += grid[i][j];
            }
        }
        if(total%2!=0) return false;

        // horizontal split
        ll upper=0;
        // m-1 kyonki last row/column ko split nhi kiya ja sakta hai
        for(int i=0; i<m-1; i++){
            upper += rowSum[i];
            if(upper == total-upper) return true;
        }

        // vertical split
        ll left=0;
        // m-1 kyonki last row/column ko split nhi kiya ja sakta hai
        for(int i=0; i<n-1; i++){
            left += colSum[i];
            if(left == total-left) return true;
        }
        return false;
    }
};
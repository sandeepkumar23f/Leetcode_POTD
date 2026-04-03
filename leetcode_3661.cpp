class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();

        vector<pair<int,int>> arr(n);
        for(int i = 0; i < n; i++) {
            arr[i] = {robots[i], distance[i]};
        }

        sort(arr.begin(), arr.end());
        sort(walls.begin(), walls.end());

        vector<vector<int>> dp(n, vector<int>(2, -1));

        auto dfs = [&](auto&& self, int i, int j) -> int {
            if(i < 0) return 0;

            if(dp[i][j] != -1) return dp[i][j];

            // LEFT
            int left = arr[i].first - arr[i].second;
            if(i > 0)
                left = max(left, arr[i-1].first + 1);

            int l = lower_bound(walls.begin(), walls.end(), left) - walls.begin();
            int r = lower_bound(walls.begin(), walls.end(), arr[i].first + 1) - walls.begin();

            int ans = self(self, i - 1, 0) + (r - l);

            // RIGHT
            int right = arr[i].first + arr[i].second;

            if(i + 1 < n) {
                if(j == 0)
                    right = min(right, arr[i+1].first - arr[i+1].second - 1);
                else
                    right = min(right, arr[i+1].first - 1);
            }

            l = lower_bound(walls.begin(), walls.end(), arr[i].first) - walls.begin();
            r = lower_bound(walls.begin(), walls.end(), right + 1) - walls.begin();

            ans = max(ans, self(self, i - 1, 1) + (r - l));

            return dp[i][j] = ans;
        };

        return dfs(dfs, n - 1, 1);
    }
};

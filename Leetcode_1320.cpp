class Solution {
public:
    int dp[301][27][27];

    int dist(int a, int b) {
        if (a == 26 || b == 26) return 0;
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int solve(string &w, int i, int f1, int f2) {
        if (i == w.size()) return 0;

        if (dp[i][f1][f2] != -1) return dp[i][f1][f2];

        int cur = w[i] - 'A';

        // Use finger 1
        int use1 = dist(f1, cur) + solve(w, i + 1, cur, f2);

        // Use finger 2
        int use2 = dist(f2, cur) + solve(w, i + 1, f1, cur);

        return dp[i][f1][f2] = min(use1, use2);
    }

    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        return solve(word, 0, 26, 26); // 26 = unused
    }
};

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = 2 * n;

        vector<int> d(m, m);

        unordered_map<int, int> last;
        for (int i = 0; i < m; i++) {
            int x = nums[i % n];
            if (last.count(x)) {
                d[i] = i - last[x];
            }
            last[x] = i;
        }

        unordered_map<int, int> next_;
        for (int i = m - 1; i >= 0; i--) {
            int x = nums[i % n];
            if (next_.count(x)) {
                d[i] = min(d[i], next_[x] - i);
            }
            next_[x] = i;
        }

        for (int i = 0; i < n; i++) {
            d[i] = min(d[i], d[i + n]);
        }

        vector<int> res;
        for (int q : queries) {
            if (d[q] >= n) res.push_back(-1);
            else res.push_back(d[q]);
        }

        return res;
    }
};
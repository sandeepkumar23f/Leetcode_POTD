class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> pos;
        long long per = 4LL * side;

        for (auto &p : points) {
            int x = p[0], y = p[1];
            if (y == 0) pos.push_back(x);
            else if (x == side) pos.push_back(side + y);
            else if (y == side) pos.push_back(3LL * side - x);
            else pos.push_back(4LL * side - y);
        }

        sort(pos.begin(), pos.end());
        int n = pos.size();

        vector<long long> ext = pos;
        for (int i = 0; i < n; i++) {
            ext.push_back(pos[i] + per);
        }

        auto can = [&](long long d) {
            for (int i = 0; i < n; i++) {
                int count = 1;
                long long last = ext[i];
                int idx = i;

                while (count < k) {
                    long long target = last + d;
                    auto it = lower_bound(ext.begin() + idx + 1, ext.begin() + i + n, target);
                    if (it == ext.begin() + i + n) break;
                    last = *it;
                    idx = it - ext.begin();
                    count++;
                }

                if (count >= k && last - ext[i] <= per - d)
                    return true;
            }
            return false;
        };

        long long lo = 0, hi = per, ans = 0;
        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            if (can(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};

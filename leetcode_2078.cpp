class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int dist=INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(colors[i]!=colors[j]){
                    dist = max(dist,abs(j-i));
                }
            }
        }
        return dist;
    }
};

// approach 2

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (colors[i] != colors[0]) {
                ans = i;
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (colors[i] != colors[n - 1]) {
                ans = max(ans, n - 1 - i);
                break;
            }
        }

        return ans;
    }
};
class Solution {
public:
    int dp[501][501];
    int rec(int i, int j, vector<int>& piles) {
        // base
        if (i == j)
            return piles[i];

        // memo
        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MIN;
        ans = max(ans, piles[i] - rec(i + 1, j, piles));
        ans = max(ans, piles[j] - rec(i, j - 1, piles));
        return dp[i][j] = ans;
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(dp, -1, sizeof(dp));
        return rec(0, n - 1, piles) > 0;
    }
};

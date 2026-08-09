class Solution {
public:
    int n;
    vector<int> suffix;
    vector<vector<int>> dp;

    int solve(int i, int M) {
        // All piles have been taken
        if (i >= n) {
            return 0;
        }

        // Already calculated
        if (dp[i][M] != -1) {
            return dp[i][M];
        }

        // We can take all remaining piles
        if (2 * M >= n - i) {
            return dp[i][M] = suffix[i];
        }

        int best = 0;

        // Try taking X piles, where 1 <= X <= 2 * M
        for (int X = 1; X <= 2 * M; X++) {
            int nextM = max(M, X);

            // Current player gets everything remaining
            // except what the opponent can get afterward.
            int currentStones =
                suffix[i] - solve(i + X, nextM);

            best = max(best, currentStones);
        }

        return dp[i][M] = best;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        // suffix[i] = total stones from i to the end
        suffix.resize(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        // M can never become greater than n
        dp.assign(n, vector<int>(n + 1, -1));

        return solve(0, 1);
    }
};
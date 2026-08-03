class Solution {
public:
    int dp[50005];

    int rec(int i, vector<int>& val) {
        // base
        int n = val.size();
        if (i >= n)
            return 0;

        // memo
        if (dp[i] != -1)
            return dp[i];

        // condition
        int ans = INT_MIN;
        int take = 0;
        for (int k = 0; k < 3 && i + k < n; k++) {
            take += val[k + i];
            ans = max(ans, take - rec(i + k + 1, val));
        }

        // save & return
        return dp[i] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        memset(dp, -1, sizeof(dp));
        int scoreDiff = rec(0, stoneValue);
        if (scoreDiff > 0)
            return "Alice";
        else if (scoreDiff < 0)
            return "Bob";
        return "Tie";
    }
};
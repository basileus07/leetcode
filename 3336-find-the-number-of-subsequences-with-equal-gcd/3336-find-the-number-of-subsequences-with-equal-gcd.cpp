class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[201][201][201];

    int rec(int i, int gcd1, int gcd2, vector<int>& nums) {
        // base
        if (i >= nums.size()) {
            if (gcd1 != 0 && gcd1 == gcd2)
                return 1;
            return 0;
        }

        // memo
        if (dp[i][gcd1][gcd2] != -1) {
            return dp[i][gcd1][gcd2];
        }

        // ans formation
        long long ans = 0;

        // 3 choice take in seq1, take in seq2 and skip

        // skip
        ans += rec(i + 1, gcd1, gcd2, nums);

        // put in seq1
        ans += rec(i + 1, gcd(gcd1, nums[i]), gcd2, nums);

        // put in seq2
        ans += rec(i + 1, gcd1, gcd(gcd2, nums[i]), nums);

        // return
        return dp[i][gcd1][gcd2] = ans % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return rec(0, 0, 0, nums);
    }
};
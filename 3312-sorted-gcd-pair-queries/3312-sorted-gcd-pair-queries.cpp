class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        // freq[x] = how many times x appears
        vector<long long> freq(mx + 1, 0);
        for (int x : nums) freq[x]++;

        // exact[g] = number of pairs whose gcd is exactly g
        vector<long long> exact(mx + 1, 0);

        // Process from large to small
        for (int g = mx; g >= 1; g--) {

            // Count numbers divisible by g
            long long cnt = 0;
            for (int multiple = g; multiple <= mx; multiple += g)
                cnt += freq[multiple];

            // Total pairs divisible by g
            long long pairs = cnt * (cnt - 1) / 2;

            // Remove pairs whose gcd is a multiple of g
            for (int multiple = 2 * g; multiple <= mx; multiple += g)
                pairs -= exact[multiple];

            exact[g] = pairs;
        }

        // Prefix sums:
        // prefix[g] = number of pairs with gcd <= g
        vector<long long> prefix(mx + 1, 0);
        for (int g = 1; g <= mx; g++)
            prefix[g] = prefix[g - 1] + exact[g];

        vector<int> ans;

        for (long long q : queries) {
            // Find first gcd whose prefix > q
            int g = lower_bound(prefix.begin() + 1, prefix.end(), q + 1) - prefix.begin();
            ans.push_back(g);
        }

        return ans;
    }
};
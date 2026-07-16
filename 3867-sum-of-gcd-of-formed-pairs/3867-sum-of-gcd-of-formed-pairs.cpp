class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            nums[i] = gcd(nums[i], mx);
        }

        sort(nums.begin(), nums.end());

        int i = 0, j = n - 1;
        long long ans = 0;
        while (i < j) {
            ans += gcd(nums[i], nums[j]);
            i++;
            j--;
        }

        return ans;
    }
};
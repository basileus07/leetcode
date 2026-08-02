class Solution {
public:
    int rec(int i, int j, vector<int>& nums) {
        // base
        if (i == j)
            return nums[j];

        int ans = INT_MIN;
        ans = max(ans, nums[i] - rec(i + 1, j, nums));
        ans = max(ans, nums[j] - rec(i, j - 1, nums));

        return ans;
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int scoreDiff = rec(0, n - 1, nums);
        return scoreDiff >= 0;
    }
};
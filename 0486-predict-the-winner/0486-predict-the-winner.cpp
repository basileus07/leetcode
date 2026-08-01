class Solution {
public:
    // optimal straegy game (min-max game)

    int rec(int i, int j, vector<int>& nums) {

        if (i > j)
            return 0;
        if (i == j) {
            return nums[i];
        }

        return max(nums[i] - rec(i + 1, j, nums),
                   nums[j] - rec(i, j - 1, nums));
    }

    bool predictTheWinner(vector<int>& nums) {
        int totalScore = accumulate(nums.begin(), nums.end(), 0);

        return rec(0, nums.size() - 1, nums) >= 0;
    }
};
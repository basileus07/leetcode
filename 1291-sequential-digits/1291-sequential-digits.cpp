class Solution {
public:
    void dfs(string num, int low, int high, vector<int>& ans) {
        int value = stoi(num);

        if (value > high)
            return;

        if (value >= low)
            ans.push_back(value);

        int last = num.back() - '0';

        if (last == 9)
            return;

        num.push_back(last + 1 + '0');
        dfs(num, low, high, ans);
    }

    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        for (int i = 1; i <= 9; i++) {
            string num;
            num.push_back(i + '0');
            dfs(num, low, high, ans);
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};
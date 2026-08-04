class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = 100;
        int mx = 1;
        unordered_map<int, bool> mp;

        for (auto x : nums) {
            mn = min(mn, x);
            mx = max(mx, x);
            mp[x] = true;
        }

        vector<int> ans;
        for (int i = mn; i <= mx; i++) {
            if (!mp[i])
                ans.push_back(i);
        }

        return ans;
    }
};
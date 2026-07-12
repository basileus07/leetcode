class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.size() < 1)
            return {};
        vector<int> newArr = arr;
        sort(newArr.begin(), newArr.end());
        unordered_map<int, int> mp;
        int rank = 1;
        mp[newArr[0]] = rank;
        for (int i = 1; i < arr.size(); i++) {
            if (newArr[i] != newArr[i - 1]) {
                mp[newArr[i]] = rank + 1;
                rank++;
            }
        }

        vector<int> ans;
        for (int i = 0; i < arr.size(); i++) {
            ans.push_back(mp[arr[i]]);
        }

        return ans;
    }
};
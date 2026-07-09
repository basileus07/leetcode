class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& num, int maxDiff,
                                      vector<vector<int>>& queries) {

        vector<int> comp(n, 0);
        comp[0] = 1;
        for (int i = 1; i < n; i++) {
            if ((num[i] - num[i - 1]) <= maxDiff) {
                comp[i] = comp[i - 1];
            } else {
                comp[i] = comp[i - 1] + 1;
            }
        }

        vector<bool> ans;
        for (int i = 0; i < queries.size(); i++) {
            int u = queries[i][0];
            int v = queries[i][1];

            ans.push_back(comp[u] == comp[v]);
        }

        return ans;
    }
};
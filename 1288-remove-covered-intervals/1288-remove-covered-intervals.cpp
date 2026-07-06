class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> vii;
        for (int i = 0; i < n; i++) {
            vii.push_back({intervals[i][0], intervals[i][1]});
        }

        sort(vii.begin(), vii.end(), cmp);

        // for (auto it : vii) {
        //     cout << it.first << " " << it.second << endl;
        // }

        vector<bool> vis(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {
                if (!vis[j]) {
                    int c = vii[i].first;
                    int d = vii[i].second;
                    int a = vii[j].first;
                    int b = vii[j].second;
                    if (c <= a && b <= d) {
                        cnt++;
                        vis[j] = 1;
                    }
                }
            }
        }

        return n - cnt;
    }
};
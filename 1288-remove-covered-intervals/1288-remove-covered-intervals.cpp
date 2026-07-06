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

        int cnt = 0, mxEnd = 0;
        for(auto it : vii){
            if(it.second > mxEnd){
                mxEnd = it.second;
                cnt++;
            }
        }

        return cnt;
    }
};

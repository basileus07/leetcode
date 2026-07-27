class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // sqroot(x^2 + y^2)  -> pair<int, pair<int,int>>

        priority_queue<pair<int, pair<int, int>>> pq;

        for (auto i : points) {
            int x = i[0];
            int y = i[1];
            int dist = (x * x) + (y * y);
            cout << dist << endl;
            pq.push({dist, {x, y}});

            if (pq.size() > k)
                pq.pop();
        }

        vector<vector<int>> ans;
        while (!pq.empty()) {
            auto val = pq.top().second;
            pq.pop();
            ans.push_back({val.first, val.second});
        }

        return ans;
    }
};
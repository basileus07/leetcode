class Solution {
public:
    void dfs(int node, vector<vector<int>>& g, vector<int>& vis,
             vector<int>& comp) {
        vis[node] = 1;
        comp.push_back(node);

        for (auto nxt : g[node]) {
            if (!vis[nxt])
                dfs(nxt, g, vis, comp);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);

        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            vector<int> comp;
            dfs(i, g, vis, comp);

            int vertices = comp.size();
            int degreeSum = 0;

            for (int node : comp)
                degreeSum += g[node].size();

            int actualEdges = degreeSum / 2;
            int expectedEdges = vertices * (vertices - 1) / 2;

            if (actualEdges == expectedEdges)
                ans++;
        }

        return ans;
    }
};
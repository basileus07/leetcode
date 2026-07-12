class Solution {
public:
    int ecnt;
    int ncnt;
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        ncnt++;

        for (auto v : adj[node]) {
            ecnt++;
            if (!vis[v]) {
                dfs(v, adj, vis);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto x : edges) {
            int u = x[0];
            int v = x[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ecnt = 0;
                ncnt = 0;
                dfs(i, adj, vis);
                if (ecnt == (ncnt * (ncnt - 1))) {
                    ans++;
                }
                // cout << "e:n " << ecnt << " " << ncnt << endl;
            }
        }
        return ans;
    }
};
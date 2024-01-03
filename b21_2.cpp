#include "utils.h"

int n, m, k;
vector<vector<pair<int, int>>> adj;
vector<bool> visited;
priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;

void DFS(int node, int parent, int max_edge, vector<int> &path)
{
    visited[node] = true;
    path.push_back(node);

    if (node == n - 1)
    {
        pq.push({max_edge, path});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    else
    {
        for (auto &edge : adj[node])
        {
            int next_node = edge.first;
            int weight = edge.second;
            if (!visited[next_node])
            {
                DFS(next_node, node, max(max_edge, weight), path);
            }
        }
    }
    visited[node] = false;
    path.pop_back();
}

int main()
{

    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    visited.resize(n, false);
    vector<int> path;
    DFS(0, -1, 0, path);

    vector<vector<int>> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    // print path
    // for (int i = ans.size() - 1; i >= 0; i--)
    // {
    //     for (int j = 0; j < ans[i].size(); j++)
    //     {
    //         cout << ans[i][j] + 1 << ' ';
    //     }
    //     cout << '\n';
    // }
}
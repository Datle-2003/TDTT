#include "utils.h"

// Cho một cây n đỉnh. Khoảng cách giữa 2 đỉnh u,v là số cạnh trên đường đi từ u đến v. Độ rộng của cây là tổng khoảng cách giữa tất cả cặp đỉnh u,vu<v. Hãy xác định độ rộng của cây.

void dfs(int u, int p, vector<vector<int>> &adj, vector<int> &subnodes)
{
    subnodes[u] = 1;     // itself
    for (int v : adj[u]) // for each child of u
    {
        if (v == p) // if v is parent of u, skip
            continue;
        dfs(v, u, adj, subnodes);
        subnodes[u] += subnodes[v];
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<vector<int>> adj(n);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // the width of a tree is the sum of distances between all pairs of vertices
    // using dfs, cal number of subnodes of each node(including itself)
    // the result is ans += (n - subnodes[i]) * subnodes[i]
    // where i is the root of the tree
    // why
    // because the distance between 2 nodes is the number of edges on the path between them
    // so the distance between 2 nodes is the number of nodes on the path between them - 1

    vector<int> subnodes(n, 0);

    dfs(0, -1, adj, subnodes); // root is 0, parent is -1

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (n - subnodes[i]) * subnodes[i];
    }

    cout << ans << '\n';
}
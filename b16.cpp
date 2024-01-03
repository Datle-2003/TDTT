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
    vector<int> subnodes(n, 0);

    dfs(0, -1, adj, subnodes);

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += (n - subnodes[i]) * subnodes[i];

    cout << ans << '\n';
}

/*
Đề bài: Tìm độ rộng của cây

Ý tưởng: Độ rộng của cây là tổng khoảng cách giữa tất cả cặp đỉnh u, v
        Sử dụng dfs, tính số lượng đỉnh con của mỗi đỉnh
        Kết quả là ans += (n - subnodes[i]) * subnodes[i]
        Trong đó i là đỉnh gốc của cây
        Tại sao?
        Vì khoảng cách giữa 2 đỉnh là số cạnh trên đường đi giữa chúng
        Vậy khoảng cách giữa 2 đỉnh là số đỉnh trên đường đi giữa chúng - 1
        => Khoảng cách giữa 2 đỉnh là số đỉnh con của đỉnh gốc - 1
        => Khoảng cách giữa 2 đỉnh là (n - subnodes[i]) * subnodes[i]
*/
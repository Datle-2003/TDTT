// Trong một xứ sở huyền bí, có một vương quốc tên là Graphonia, nơi có N thành phố và M con
// đường kết nối chúng với nhau. Vua của Graphonia quyết định tối ưu hóa hệ thống giao thông
// trong vương quốc của mình. Ông muốn biết số lượng thành phố mà không thể đến được nhau
// nếu loại bỏ mỗi con đường trong hệ thống giao thông

// Cho đồ thị N đỉnh, M cạnh. (Vô hướng / Có hướng)
// Yêu cầu: Với mỗi cạnh của đồ thị, cho biết có bao nhiêu cặp đỉnh (u, v) sẽ không đến được tới
// nhau nếu cạnh này bị loại bỏ

#include "utils.h"

void dfs(vector<vector<int>> adj, int u, vector<bool> &visited, int& count){
    visited[u] = true;
    count++;
    for(int i = 0; i < adj[u].size(); i++)
        if(!visited[adj[u][i]])
            dfs(adj, adj[u][i], visited, count);
}
int countDisconnectedVertices(vector<vector<int>> adj, int u, int v){
    int n = adj.size();
    vector<bool> visited(n, 0);
    int count = 0;
    dfs(adj, v, visited, count);
    if(visited[u])
        return 0;// graph is still connected because u and v still connects
    else
        return count * (n - count);// graph is divided into 2 connected subgraph
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // u--
        // v-- // if u,v starts from 1 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int res = 0;
    for(int u = 0; u < n; u++){
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            auto upos = find(adj[v].begin(), adj[v].end(), u);
            // count only if u < v to avoid repetition (undirected graph)
            if(u > v)
                continue;
            // remove (u, v) and (v, u)
            adj[u].erase(adj[u].begin() + i);
            adj[v].erase(upos);
            // count when (u, v) is removed
            cout << countDisconnectedVertices(adj, u, v) << "\n";
            // insert (u, v) and (v, u) back
            adj[v].insert(upos, u);
            adj[u].insert(adj[u].begin() + i, v); 
        }
    }
}
// Trong một xứ sở huyền bí, có một vương quốc tên là Graphonia, nơi có N thành phố và M con
// đường kết nối chúng với nhau. Vua của Graphonia quyết định tối ưu hóa hệ thống giao thông
// trong vương quốc của mình. Ông muốn biết số lượng thành phố mà không thể đến được nhau
// nếu loại bỏ mỗi con đường trong hệ thống giao thông

// Cho đồ thị N đỉnh, M cạnh. (Vô hướng / Có hướng)
// Yêu cầu: Với mỗi cạnh của đồ thị, cho biết có bao nhiêu cặp đỉnh (u, v) sẽ không đến được tới
// nhau nếu cạnh này bị loại bỏ

#include "utils.h"

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
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    
}
// // có N thành phố và M tuyến đường tàu hỏa kết nối chúng với nhau. Độ dài của
// // mỗi tuyến đường là khác nhau, và đảm bảo rằng giữa bất kỳ cặp thành phố nào cũng tồn tại ít
// // nhất một tuyến đường (trực tiếp hoặc gián tiếp) nối chúng

// // Chính phủ quyết định nâng cấp các tuyến đường thành hệ thống tàu siêu tốc mới, đảm bảo rằng
// // giữa mỗi cặp thành phố luôn tồn tại ít nhất một tuyến đường sử dụng công nghệ mới này. Mục
// // tiêu của chính phủ là tìm ra kế hoạch tối ưu sao cho tổng độ dài của các tuyến đường cần nâng
// // cấp là ít nhất

// // Tuy nhiên, để đối phó với tình huống có thể xảy ra sự cố, chính phủ cũng muốn xác định K kế
// // hoạch khác nhau. Hai kế hoạch được coi là khác nhau nếu ít nhất một tuyến đường được nâng
// // cấp trong một kế hoạch nhưng không được nâng cấp trong kế hoạch khác, và ngược lại. Mục tiêu
// // là tìm ra K kế hoạch dự phòng đảm bảo an toàn và tin cậy cho hệ thống tàu hỏa siêu tốc mới của
// // quốc gia

// // Yêu cầu: In ra K kế hoạch dự phòng

#include "utils.h"

struct Edge
{
    int u, v;
    int w;

    Edge(int u, int v, int w) : u(u), v(v), w(w) {}

    bool operator<(const Edge &other) const
    {
        return w < other.w;
    }

    bool operator==(const Edge &other) const
    {
        return u == other.u && v == other.v && w == other.w;
    }
};

vector<int> parent;                // lưu trữ cha của mỗi đỉnh
vector<int> _rank;                 // lưu trữ độ sâu
vector<Edge> edges;                // lưu trữ các cạnh
vector<Edge> mst_edges;            // lưu trữ các cạnh trong cây khung nhỏ nhất
vector<vector<Edge>> backup_plans; // lưu trữ các kế hoạch dự phòng
int n, m, k;

int findSet(int v)
{
    if (parent[v] == v)
        return v;
    return parent[v] = findSet(parent[v]);
}

void makeSet()
{
    for (int i = 1; i <= parent.size(); i++)
    {
        parent[i] = i;
        _rank[i] = 1;
    }
}

bool Union(int a, int b)
{
    a = findSet(a);
    b = findSet(b);
    if (a != b)
    {
        if (_rank[a] < _rank[b])
            swap(a, b);
        parent[b] = a;
        if (_rank[a] == _rank[b])
            _rank[a]++;
        return true;
    }
    return false;
}

void Kruskal()
{
    sort(edges.begin(), edges.end());
    int d = 0;

    for (Edge &e : edges)
    {
        if (mst_edges.size() == n - 1)
            break;
        if (Union(e.u, e.v))
        {
            mst_edges.push_back(e);
            d += e.w;
        }
    }
}

void DFS(int node, int parent, vector<vector<pair<int, int>>> &adj, vector<bool> &visited, vector<Edge> &mst, vector<Edge> &backup_mst) {
    visited[node] = true;
    for (auto &edge : adj[node]) {
        int next_node = edge.first;
        int weight = edge.second;
        if (!visited[next_node]) {
            Edge e = {node, next_node, weight};
            if (find(mst.begin(), mst.end(), e) != mst.end()) {
                backup_mst.push_back(e);
            }
            DFS(next_node, node, adj, visited, mst, backup_mst);
            if (find(mst.begin(), mst.end(), e) != mst.end()) {
                backup_mst.pop_back();
            }
        } else if (next_node != parent) {
            Edge e = {min(node, next_node), max(node, next_node), weight};
            if (find(mst.begin(), mst.end(), e) == mst.end()) {
                backup_mst.push_back(e);
                if (backup_mst.size() == mst.size()) {
                    backup_plans.push_back(backup_mst);
                }
                backup_mst.pop_back();
            }
        }
    }
}

void findBackupPlans() {
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto &e : edges) {
        adj[e.u].push_back({e.v, e.w});
        adj[e.v].push_back({e.u, e.w});
    }
    for (int i = 1; i <= n && backup_plans.size() < k; i++) {
        vector<bool> visited(n + 1, false);
        vector<Edge> backup_mst;
        DFS(i, -1, adj, visited, mst_edges, backup_mst);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cin >> n >> m >> k;

    parent.resize(n + 1);
    _rank.resize(n + 1);

    makeSet();

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});

        edges.push_back(Edge(u, v, w));
    }

    Kruskal();

    findBackupPlans();

    for (auto &plan : backup_plans) {
        for (auto &e : plan) {
            cout << e.u << ' ' << e.v << ' ' << e.w << '\n';
        }
        cout << '\n';
    }

}
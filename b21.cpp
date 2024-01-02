// có N thành phố và M tuyến đường tàu hỏa kết nối chúng với nhau. Độ dài của
// mỗi tuyến đường là khác nhau, và đảm bảo rằng giữa bất kỳ cặp thành phố nào cũng tồn tại ít
// nhất một tuyến đường (trực tiếp hoặc gián tiếp) nối chúng

// Chính phủ quyết định nâng cấp các tuyến đường thành hệ thống tàu siêu tốc mới, đảm bảo rằng
// giữa mỗi cặp thành phố luôn tồn tại ít nhất một tuyến đường sử dụng công nghệ mới này. Mục
// tiêu của chính phủ là tìm ra kế hoạch tối ưu sao cho tổng độ dài của các tuyến đường cần nâng
// cấp là ít nhất

// Tuy nhiên, để đối phó với tình huống có thể xảy ra sự cố, chính phủ cũng muốn xác định K kế
// hoạch khác nhau. Hai kế hoạch được coi là khác nhau nếu ít nhất một tuyến đường được nâng
// cấp trong một kế hoạch nhưng không được nâng cấp trong kế hoạch khác, và ngược lại. Mục tiêu
// là tìm ra K kế hoạch dự phòng đảm bảo an toàn và tin cậy cho hệ thống tàu hỏa siêu tốc mới của
// quốc gia

// Yêu cầu: In ra K kế hoạch dự phòng

#include "utils.h"

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }




}
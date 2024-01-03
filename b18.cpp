#include "utils.h"

// Cho dãy số a1,a2,…,an là một hoán vị của các số từ 1 đến n. Có thể thực hiện thao tác sau trên dãy số: chọn vị trí i2≤i≤n và đảo ngược thứ tự các phần tử a1,a2,…,ai, các phần tử còn lại giữ nguyên.
// Yêu cầu: Tìm số thao tác thực hiện ít nhất để dãy có thứ tự tăng dần.

void flip(string &s, int i)
{
    reverse(s.begin(), s.begin() + i + 1);
}

int bfs(string src, string dst, int n) // n is len of src and dst
{
    if (src == dst)
        return 0;

    queue<string> q;                 // queue to store states
    unordered_map<string, int> dist; // dist[u] is the distance from src to u

    q.push(src);
    while (!q.empty())
    {
        string u = q.front();
        q.pop();

        for (int i = 2; i <= n; i++)
        {
            string tmp = u;
            flip(tmp, i - 1);
            if (dist.find(tmp) == dist.end())
            {                            // not found tmp in dist
                dist[tmp] = dist[u] + 1; // mark tmp as visited
                if (tmp == dst)
                    return dist[tmp];
                q.push(tmp);
            }
        }
    }
    return -1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    string src = "";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        src += (char)('0' + x);
    }

    string dst = "";
    for (int i = 0; i < n; i++)
        dst += (char)('0' + i + 1);

    cout << bfs(src, dst, n) << '\n';
    return 0;
}

/*
Đề bài: Cho dãy a1, ...an là một hoán vị của các số từ 1 đến n. Có thể thực hiện thao tác sau trên dãy số: chọn vị trí i2≤i≤n và đảo ngược thứ tự các phần tử a1, ...ai, các phần tử còn lại giữ nguyên. Yêu cầu: Tìm số thao tác thực hiện ít nhất để dãy có thứ tự tăng dần.

Ý tưởng: Sử dụng bfs, duyệt qua các trạng thái có thể có
        Mỗi trạng thái là 1 hoán vị của các số từ 1 đến n
        Mỗi trạng thái có thể chuyển sang trạng thái khác bằng cách đảo ngược 1 đoạn từ 1 đến i
        Với i từ 2 đến n
        Tìm trạng thái đích là hoán vị tăng dần
        Trả về số bước để chuyển từ trạng thái đầu sang trạng thái đích
        Nếu không tìm được trạng thái đích, trả về -1

Độ phức tạp không gian: Mỗi trạng thái có thể sinh ra tối đa n trạng thái khác
                        => Số trạng thái tối đa là n^n
                        => Độ phức tạp không gian là O(n^n)
Thời gian: Sử dụng bfs, mỗi trạng thái có thể sinh ra tối đa n trạng thái khác
            => Độ phức tạp thời gian là O(n^n * n)
*/
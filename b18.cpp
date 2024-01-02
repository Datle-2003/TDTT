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
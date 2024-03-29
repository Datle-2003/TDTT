#include "utils.h"

bool check(int a, int b, int c, int d)
{
    return a == b && b == c && c == d;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1, -1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1));
    int res = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (check(a[i][j], a[i - 1][j - 1], a[i - 1][j], a[i][j - 1]))
            {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1;
                res = max(res, dp[i][j]);
            }
        }
    }

    cout << res * res << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();
}

/*
Đề bài: Tìm diện tích hình vuông lớn nhất

Ý tưởng: Sử dụng dp với dp[i][j] là độ dài cạnh hình vuông lớn nhất có đỉnh phải dưới là (i, j)
        dp[i][j] = 1

        dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1 nếu a[i][j] == a[i - 1][j - 1] == a[i - 1][j] == a[i][j - 1]

        Kết quả là max(dp[i][j]) * max(dp[i][j])

Thời gian: O(n * m)
Độ phức tạp không gian: O(n * m)
*/
#include "utils.h"

// Xét k cụm dữ liệu, mỗi cụm dữ liệu được chia thành 2 nhóm: nhóm loại 1 và nhóm loại 2. Cụm dữ liệu thứ i có trọng số các nhóm tương ứng ai,bi. Cần chọn ra n nhóm loại 1 và m nhóm loại 2 trong các cụm dữ liệu để làm mẫu thử với nguyên tắc mỗi cụm dữ liệu chỉ chọn 1 nhóm, do đó n+m≤k.
// Yêu cầu: Tìm cách chọn các nhóm dữ liệu trong mỗi cụm sao cho tổng trọng số của tất cả các nhóm được chọn là lớn nhất.

int main()
{
    int k, n, m;
    cin >> k >> n >> m;
    int t = k - n - m;
    vector<int> a(k), b(k);
    for (int i = 0; i < k; i++)
    {
        cin >> a[i] >> b[i];
    }
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(t + 1, 0)));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int l = 0; l <= t; l++)
            {
                int idx = i + j + l; // 0-based
                if (i + 1 <= n)
                    dp[i + 1][j][l] = max(dp[i + 1][j][l], dp[i][j][l] + a[idx]);
                if (j + 1 <= m)
                    dp[i][j + 1][l] = max(dp[i][j + 1][l], dp[i][j][l] + b[idx]);
                if (l + 1 <= t)
                    dp[i][j][l + 1] = max(dp[i][j][l + 1], dp[i][j][l]);
            }
        }
    }
    cout << dp[n][m][t] << '\n';
    return 0;
}
//k
// chon n + m 
// tai i, phan tu dau tien cua ca 2 mang -> toi uu la i - 1, i -2
// dp[i][m][n]: tong lon nhat cua i phan tu dau tien trong mang, m phan tu mang thu nhat , n phan tu mang 2
// dp[i + 1][j][k]: 
// + chon phan tu o vi tri thu i cua mang a
// + chon phan tu o vi tri thu i cua mang b
// + khong chon phan tu o vi tri thu i cua mang nao ca
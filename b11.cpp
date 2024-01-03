#include "utils.h"

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
                int idx = i + j + l;
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

/*
Đề bài: Cho k cụm dữ liệu, mỗi cụm có 2 phần tử. Chọn n phần tử ở cụm 1 và m phần tử ở cụm 2

Ý tưởng: Sử dụng dp 
        dp[i][j][l]: tổng lớn nhất khi chọn i phần tử ở cụm 1, j phần tử ở cụm 2, bỏ qua l cụm

        + Chọn phần tử ở cụm 1: dp[i + 1][j][l] = max(dp[i + 1][j][l], dp[i][j][l] + a[idx]) 
        + Chọn phần tử ở cụm 2: dp[i][j + 1][l] = max(dp[i][j + 1][l], dp[i][j][l] + b[idx])
        + Không chọn phần tử nào: dp[i][j][l + 1] = max(dp[i][j][l + 1], dp[i][j][l])

Độ phức tạp thời gian: O(n * m * t)
Độ phức tạp không gian: O(n * m * t)
*/
















//k
// chon n + m 
// tai i, phan tu dau tien cua ca 2 mang -> toi uu la i - 1, i -2
// dp[i][m][n]: tong lon nhat cua i phan tu dau tien trong mang, m phan tu mang thu nhat , n phan tu mang 2
// dp[i + 1][j][k]: 
// + chon phan tu o vi tri thu i cua mang a
// + chon phan tu o vi tri thu i cua mang b
// + khong chon phan tu o vi tri thu i cua mang nao ca
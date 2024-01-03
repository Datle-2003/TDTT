#include "utils.h"

// Xét k cụm dữ liệu, mỗi cụm dữ liệu được chia thành 2 nhóm: nhóm loại 1 và nhóm loại 2. Cụm dữ liệu thứ i có trọng số các nhóm tương ứng ai,bi. Cần chọn ra n nhóm loại 1 và m nhóm loại 2 trong các cụm dữ liệu để làm mẫu thử với nguyên tắc mỗi cụm dữ liệu chỉ chọn 1 nhóm, do đó n+m≤k.
// Yêu cầu: Tìm cách chọn các nhóm dữ liệu trong mỗi cụm sao cho tổng trọng số của tất cả các nhóm được chọn là lớn nhất.

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int k, n, m;
    cin >> k >> n >> m;
    vector<int> a(k + 1), b(k + 1);
    for (int i = 1; i <= k; i++){
        cin >> a[i] >> b[i];
    }
    vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(n + 1, vector<int>(m + 1, 0)));
    for (int i = 1; i <= k; i++){
        for (int j = 0; j <= n; j++){
            for (int l = 0; l <= m; l++){

                if(j + l > i)
                    continue;
                if(j > 0)
                    dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j - 1][l] + a[i]);
                if(l > 0)
                    dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j][l - 1] + b[i]);
                if(j + l <= i - 1)
                    dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j][l]);
            }
        }
    }

    cout << dp[k][n][m] << '\n';
    return 0;
}

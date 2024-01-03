// Regular Expression Matching
#include "utils.h"

bool bruteForce(string s, string p, int i, int j)
{
    if (i == s.size() && j == p.size())
        return true;
    if (j == p.size())
        return false;

    bool match = i < s.size() && (s[i] == p[j] || p[j] == '.');

    if (j + 1 < p.size() && p[j + 1] == '*')
    {
        return bruteForce(s, p, i, j + 2) || (match && bruteForce(s, p, i + 1, j));
    }

    return match && bruteForce(s, p, i + 1, j + 1);
}

bool topdown(string s, string p, int i, int j, vector<vector<int>> &dp)
{
    if (i == s.size() && j == p.size())
        return true;
    if (j == p.size())
        return false;

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    bool match = i < s.size() && (s[i] == p[j] || p[j] == '.');

    if (j + 1 < p.size() && p[j + 1] == '*')
    {
        dp[i][j] = topdown(s, p, i, j + 2, dp) || (match && topdown(s, p, i + 1, j, dp));
        return dp[i][j];
    }
    dp[i][j] = match && topdown(s, p, i + 1, j + 1, dp);
    return dp[i][j];
}

void solve()
{
    string s, p;
    // cin >> s >> p;
    s = "cababbbcbbcbaacbc";
    p = "b*a*c*a*.*c*.*.*.*a";
    int n = s.size(), m = p.size();
    vector<vector<int>> dp(n + 1, vector<int>(m, -1));
    cout << topdown(s, p, 0, 0, dp) << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();
}

/*
Đề bài: Kiểm tra xem một chuỗi có khớp với một biểu thức chính quy hay không

Ý tưởng: 
Kiểm tra s[i] == p[j] || p[j] == '.'
    nếu đúng, kiểm tra p[j + 1] == '*'
        nếu đúng, kiểm tra 2 trường hợp:
            không dùng * -> i, j + 2
            dùng * -> i + 1, j
    Kiểm tra s[i + 1] == p[j + 1]
        nếu đúng, i + 1, j + 1

Sử dụng dp để giảm số lượng tính toán lại

Thời gian: O(m * n) do mỗi vị trí chỉ cần tính 1 lần
Độ phức tạp không gian: O(n * m)

*/
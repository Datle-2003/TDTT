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
        cout << "index" << i << " " << j << endl;
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



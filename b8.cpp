#include "utils.h"

const int N = 9;
int row[N], col[N], diag1[2 * N - 1], diag2[2 * N - 1];

vector<vector<string>> res;
bool canPlace(int i, int j, int n)
{
    return !row[i] && !col[j] && !diag1[i + j] && !diag2[i - j + n - 1];
}

void place(int i, int j, int n)
{
    row[i] = col[j] = diag1[i + j] = diag2[i - j + n - 1] = 1;
}

void backtracking(vector<string> &curr, int n, int i)
{
    if (i == n)
    {
        res.push_back(curr);
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (canPlace(i, j, n))
        {
            place(i, j, n);
            curr[i][j] = 'Q';
            backtracking(curr, n, i + 1);
            curr[i][j] = '.';
            row[i] = col[j] = diag1[i + j] = diag2[i - j + n - 1] = 0;
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<string> curr(n, string(n, '.'));
    backtracking(curr, n, 0);
    cout << res.size() << "\n";
    for (auto &x : res)
    {
        for (auto &y : x)
        {
            cout << y << "\n";
        }
        cout << "\n";
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();
}
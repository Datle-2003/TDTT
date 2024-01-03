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

/*
Bài toán: Cho một bàn cờ vua kích thước n x n. Hãy đặt n quân hậu vào bàn cờ sao cho không có quân hậu nào ăn được quân hậu khác.

Ý tưởng: Đây là bài toán kinh điển, sử dụng thuật toán backtracking(quay lui)
        Thuật toán backtracking sẽ duyệt qua tất cả các trường hợp có thể xảy ra
        Thuật toán bắt đầu bằng cách thử đặt quân hậu vào mỗi ô trên hàng đầu tiên, sau đó tiếp tục đặt ở hàng tiếp theo sao cho không vi phạm ràng buộc
        Nếu đặt được quân hậu vào hàng cuối cùng thì đây là 1 trường hợp hợp lệ, ngược lại thì không
        Nếu không đặt được quân hậu vào hàng cuối cùng thì quay lui lại và thử đặt quân hậu vào ô tiếp theo

Độ phức tạp: O(n!). Với mỗi ô trên hàng đầu tiên, ta có n cách đặt quân hậu, với mỗi cách đặt quân hậu trên hàng đầu tiên, ta có n - 1 cách đặt quân hậu trên hàng thứ 2, với mỗi cách đặt quân hậu trên hàng thứ 2, ta có n - 2 cách đặt quân hậu trên hàng thứ 3, v.v...
            Tổng số cách đặt quân hậu là n * (n - 1) * (n - 2) * ... * 1 = n!

Không gian: O(n^2)

*/
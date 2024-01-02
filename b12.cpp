#include "utils.h"

struct Point
{
    int x, y;
    Point(int x, int y) : x(x), y(y)
    {
    }
};

pair<int, int> find(int n)
{
    for (int i = 1; i * i <= n; i++)
    {
        int sq = i * i;
        int diff = n - sq;
        int diffSqrt = sqrt(diff);
        if (diffSqrt * diffSqrt == diff && diffSqrt > 0)
            return {i, diffSqrt};
    }
    return {-1, -1};
}

void solve()
{
    int n;
    cin >> n;
    pair<int, int> res = find(n);
    if (res.first == -1)
    {
        cout << "Impossible" << endl;
    }
    else
    {
        Point p1(res.first, res.second);
        Point p2(p1.x + res.first, p1.y + res.second);
        Point p3(p2.x + res.second, p2.y - res.first);
        Point p4(p3.x - res.first, p3.y - res.second);

        cout << p1.x << " " << p1.y << endl;
        cout << p2.x << " " << p2.y << endl;
        cout << p3.x << " " << p3.y << endl;
        cout << p4.x << " " << p4.y << endl;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();
}
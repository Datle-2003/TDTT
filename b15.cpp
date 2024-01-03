#include "utils.h"

double PI = 3.14159265358979323846;

struct Point
{
    int x, y;
    Point(int x, int y) : x(x), y(y)
    {
    }

    double distance(Point &other)
    {
        return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }
};

void solve()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    Point O1(x1, y1), O2(x2, y2);

    int r;
    cin >> r;

    double area = r * r * PI;
    double d = O1.distance(O2);
    if (d >= 2 * r)
    {
        cout << fixed << setprecision(3) << 2 * area << endl;
        return;
    }
    double alpha = acos(0.5 * d / r) * 2;
    double S = alpha * area / (2 * PI);
    double triangleArea = 0.5 * r * r * sin(alpha);
    double sectorArea = S - triangleArea;
    double overlapArea = 2 * sectorArea;

    cout << fixed << setprecision(3) << 2 * area - overlapArea << endl;

}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();
}


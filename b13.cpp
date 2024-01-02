#include "utils.h"

struct Point
{
    int x, y;
    Point(int x, int y) : x(x), y(y) {}

    bool operator==(const Point &other)
    {
        return x == other.x && y == other.y;
    }
};

double calcArea(Point &a, Point &b, Point &c)
{
    return 0.5 * (a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y));
}

double cosC(double a, double b, double c)
{
    return (a * a + b * b - c * c) / (2 * a * b);
}

double calcDistance(Point &a, Point &b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) +
                (a.y - b.y) * (a.y - b.y));
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<Point> a(n, Point(0, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }

    // first solution, O(n ^ 2)
    //  Point p = a[0];

    // for (int i = 1; i < n; i++)
    // {
    //     Point q = a[i];

    //     int count1 = 0, count2 = 0;
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (a[j] == p || a[j] == q)
    //             continue;
    //         Point r = a[j];
    //         double area = calcArea(p, q, r);
    //         if (area > 0)
    //             count1++;
    //         else if (area < 0)
    //             count2++;
    //     }

    //     if (count1 == count2)
    //     {
    //         cout << 1 << " " << i + 1 << endl;
    //         return 0;
    //     }
    // }

    // second solution, O(n log n)

    vector<tuple<int, int, int>> b;
    for (int i = 0; i < n; i++)
    {
        b.push_back(make_tuple(a[i].x, a[i].y, i)); 
    }

    sort(b.begin(), b.end(), [](tuple<int, int, int> &u, tuple<int, int, int> &v)
         { return get<0>(u) < get<0>(v) || (get<0>(u) == get<0>(v) && get<1>(u) < get<1>(v)); });

    tuple<int, int, int> p = b[0];
    vector<double> cosines(n, 0);
    map<double, tuple<int, int, int>> m;
    for (int i = 1; i < n; i++)
    {
        tuple<int, int, int> q = b[i];
        Point r(get<0>(q), 0);
        Point p1(get<0>(p), get<1>(p)), q1(get<0>(q), get<1>(q));
        double cos = cosC(calcDistance(p1, q1), calcDistance(p1, r), calcDistance(q1, r));
        cosines[i] = cos;
        m[cos] = q;
    }

    sort(cosines.begin(), cosines.end());
    double median = cosines[cosines.size() / 2]; // n chẵn -> cosines.size() lẻ -> median là phần tử ở giữa
    tuple<int, int, int> q = m[median];

    cout << get<2>(p) + 1 << " " << get<2>(q) + 1 << endl;
}

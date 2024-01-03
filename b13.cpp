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

   

    vector<tuple<int, int, int>> b;
    for (int i = 0; i < n; i++)
        b.push_back(make_tuple(a[i].x, a[i].y, i));
    tuple<int, int, int> p = b[0];
    for (int i = 1; i < n; i++)
    {
        tuple<int, int, int> q = b[i];
        if (get<0>(q) < get<0>(p) || (get<0>(q) == get<0>(p) && get<1>(q) < get<1>(p)))
            p = q;
    }

    vector<double> cosines(n, 0);
    unordered_map<double, tuple<int, int, int>> m;
    for (int i = 1; i < n; i++)
    {
        tuple<int, int, int> q = b[i];
        Point r(get<0>(q), 0);
        Point p1(get<0>(p), get<1>(p)), q1(get<0>(q), get<1>(q));
        double cos = cosC(calcDistance(p1, q1), calcDistance(p1, r), calcDistance(q1, r));
        cosines[i] = cos;
        m[cos] = q;
    }

    // sort(cosines.begin(), cosines.end());
    // double median = cosines[cosines.size() / 2]; // n chẵn -> cosines.size() lẻ -> median là phần tử ở giữa
    // tuple<int, int, int> q = m[median];


    tuple<int, int, int> q = m[median];

    cout << get<2>(p) + 1 << " " << get<2>(q) + 1 << endl;
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

/*
Đề bài: cho n điểm, n chẵn trên một mp, tìm 2 điểm sao cho đường thẳng đi qua 2 điểm đó cắt nửa mp thành 2 nửa có số điểm mỗi bên bằng nhau

Ý tưởng: Vì n chẵn, suy ra khi ta chọn 1 điểm bất kỳ thì sẽ có một điểm nào đó ở trong tập điểm còn lại có thể kết hợp với điểm chọn ban đầu để chia
        mp thành 2 nửa có số điểm bằng nhau. Vì vậy, ta có thể chọn điểm đầu tiên bất kỳ, sau đó duyệt qua các điểm còn lại, Lần lượt kiểm tra các điểm trong
        tập còn lại có thể kết hợp với điểm đầu tiên để chia mp thành 2 nửa có số điểm bằng nhau hay không. Nếu có thì in ra 2 điểm đó, kết thúc chương trình.
        Đường có thể chia mp thành 2 nửa có số điểm bằng nhau khi số điểm tạo bởi q, p, r theo chiều kim đồng hồ bằng số điểm tạo bởi q, p, r theo chiều ngược kim đồng hồ.

    Độ phức tạp thời gian: O(n^2)
    Không gian: O(1)

    Cải tiến:
*/





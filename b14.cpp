#include "utils.h"

const double inf = 1e9;

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
    return abs(0.5 * (a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y)));
}

double calcArea(vector<Point> &p)
{
    double area = 0;
    for (int i = 0; i < p.size(); i++)
    {
        int j = (i + 1) % p.size();
        area += p[i].x * p[j].y - p[j].x * p[i].y;
    }
    return abs(area) / 2;
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

    double total = calcArea(a);
    int j = 1;
    int first = 0, second = 1;
    double cur = 0, diff = inf;
    for (int i = 0; i < n; i++)
    {
        while (cur < total - cur)
        {
            if (abs(total - 2 * cur) < diff)
            {
                diff = abs(total - 2 * cur);
                first = i;
                second = j;
            }
            cur += calcArea(a[i], a[j], a[(j + 1) % n]);
            j = (j + 1) % n;
        }
        if (abs(total - 2 * cur) < diff)
        {
            diff = abs(total - 2 * cur);
            first = i;
            second = j;
        }
        cur -= calcArea(a[i], a[(i + 1) % n], a[j]);
    }
    cout << first + 1 << ' ' << second + 1 << '\n';
}

/*
Đề bài: Tìm 2 điểm chia đa giác thành 2 phần có diện tích chênh lệch nhỏ nhất

Ý tưởng: Tính diện tích tam giác, sau đó duyệt qua từng cặp điểm, tính diện tích 2 phần
        Lấy cặp điểm có diện tích chênh lệch nhỏ nhất
        Tại đỉnh i = 0, thực hiện chạy con trỏ j cho tới khi diện tích 2 phần lớn hơn diện tích còn lại
        Tận dụng bước trươc đó, chỉ cần dịch con trỏ i sang phải 1 bước, còn con trỏ j thì vẫn giữ nguyên
        Khi đó, ta tìm được tất cả cặp điểm có diện tích chênh lệch nhỏ nhất với từng điểm i
        
        Độ phức tạp: O(n) do con trỏ i duyệt mảng 1 lần, con trỏ j chạy tối đa n lần    
        Không gian: O(1)
*/
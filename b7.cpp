// Cho một dãy gồm n số nguyên không âm là giá trị độ cao của một vùng đất. Một cơn mưa đủ nhiều đổ lên vùng đất này và nước còn đọng lại như hình bên dưới. Biết rằng nước có thể chảy về các vị trí thấp hơn kề cạnh nếu mực nước ở vị trí hiện tại lớn hơn vị trí kề cạnh. Hai biên của vùng đất là biển và có mực nước bằng 0.

#include "utils.h"

void solve()
{
    string s; 
    cin >> s;
    stringstream ss(s);
    vector<int> a;
    int num;
    char c;
    while (ss >> num)
    {
        a.push_back(num);
        if (!(ss >> c))
            break;
    }

    int n = a.size();
    int maxLeft = a[0], maxRight = a[n - 1];
    int l = 0, r = n - 1;
    int trappedWater = 0;
    // for each position, trapped water will base on the min of maxLeft and maxRight minus the height of the position
    // if the height of the position is greater than the min of maxLeft and maxRight, then the trapped water will be 0 and update the maxLeft or maxRight
    // if the height of the position is less than the min of maxLeft and maxRight, then the trapped water will be the min of maxLeft and maxRight minus the height of the position


    while (l <= r)
    {
        maxLeft = max(maxLeft, a[l]);
        maxRight = max(maxRight, a[r]);

        if (maxLeft < maxRight)
        {
            trappedWater += maxLeft - a[l] > 0 ? maxLeft - a[l] : 0;
            l++;
        }
        else
        {
            trappedWater += maxRight - a[r] > 0 ? maxRight - a[r] : 0;
            r--;
        }
    }

    cout << trappedWater << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();
}
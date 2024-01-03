#include "utils.h"

long long dictOrder(vector<long long> p, vector<int> vals, vector<long long> facts){
    int n = p.size();
    int pos;
    long long res = 0;
    for(int i = 0; i < n; i++){
        int val = p[i];
        int j;
        // find index of val in vals
        for(j = 0; j < vals.size(); j++)
            if(val == vals[j]){
                pos = j;
                break;
            }
        res += facts[n - i - 1] * j;
        vals.erase(vals.begin() + j);
    }
    return res + 1;
}

vector<int> permutationOrder(long long order, int n, vector<long long> facts, vector<int> vals){
    vector<int> res;
    int val;
    order--;
    for(int i = n - 1; i >= 0; i--){
        long long pos = order / facts[i];
        res.push_back(vals[pos]);
        vals.erase(vals.begin() + pos);
        order -= pos * facts[i];
    }
    return res;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<long long> p;
    long long x;
    while (cin >> x){
        p.push_back(x);
    }
    x = p.back();
    p.pop_back();
    int n = p.size();

    vector<int> vals(p.size());
    for(int i = 0; i < p.size(); i++)
        vals[i] = i + 1;

    vector<long long> facts(p.size() + 1, 1);
    for (int i = 1; i <= p.size(); i++)
    {
        facts[i] = facts[i - 1] * i;
    }

    cout << dictOrder(p, vals, facts) << "\n";
    
    vector<int> res = permutationOrder(x, n, facts, vals);
    for (int val : res)
        cout << val << ' ';
    cout << '\n';
    
    return 0;
}
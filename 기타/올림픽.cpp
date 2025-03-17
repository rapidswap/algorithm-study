#include<iostream>
#include<vector>
#include<string>

#include<algorithm>

using namespace std;

struct medal
{
    int country;
    int gold;
    int silver;
    int bronze;
};

bool cmp(const medal& a, const medal& b)
{
    if (a.gold == b.gold)
    {
        if (a.silver == b.silver)
        {
            return a.bronze > b.bronze;
        }
        return a.silver > b.silver;
    }
    return a.gold > b.gold;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    medal country[1001];
    for (int i = 0; i < n; i++)
    {
        
        cin >>country[i].country>> country[i].gold >> country[i].silver >> country[i].bronze;
    }

    sort(country, country + (n+1), cmp);
    int target = -1;
    for (int i = 0; i < n; i++)
    {
        if (country[i].country == m)
        {
            target = i;
        }
    }
    
    int cnt = 0;
    for (int i = target; target > 0; i--)
    {
        if (country[target].gold == country[i-1].gold && country[target].silver == country[i-1].silver && country[target].bronze == country[i-1].bronze)
        {
            continue;
        }
        else
        {
            cnt = i + 1;
            break;
        }

    }
    if (cnt == 0)
    {
        cout << cnt + 1;
        return 0;
    }
    cout << cnt;
    return 0;
}

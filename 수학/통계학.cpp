#include<iostream>
#include<vector>
#include<string>

#include<algorithm>
#include<queue>
#include<unordered_map>
#include<cmath>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n;
    cin >> n;
    double sum = 0;
    unordered_map<int, int> m;
    vector<int>num(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        sum += num[i];
        m[num[i]]++;
    }
    vector<pair<int, int>> v(m.begin(), m.end());
    sort(num.begin(), num.end());

    if (round(sum / n) == -0)
        cout << 0<<"\n";
    else
        cout << round(sum / n) << "\n";
  

    cout << num[n / 2]<<'\n';

    sort(v.begin(), v.end(), cmp);
    if (v.size() > 1 && v[0].second == v[1].second) 
        cout << v[1].first << '\n'; 
    else
        cout << v[0].first << '\n'; 


    if (num.size() > 1)
        cout << num[n - 1] - num[0] << '\n';
    else cout << 0;
    
    
    


    return 0;
}

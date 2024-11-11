#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <deque>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    vector<int> v;
    map<int, int> m;
    while (n--)
    {
        int num;
        cin >> num;
        m[num]++;
        v.push_back(num);
    }
    
    int Max = 0;
    for (auto a : m)
    {
        if (Max < a.second) Max = a.second;
    }
    cout << Max << '\n';
    for (int i = 0; i < v.size(); i++)
    {
        int cnt = 0;
        if (i == v.size() - 1)
        {
            cout << -1;
            break;
        }
        for (int j = v.size() - 1; j >= i+1; j--)
        {
            
            if (m[v[i]] == Max) {
                cout << -1 << " ";
                break;
            }
            if (m[v[i]] < m[v[j]])
            {
                cnt++;
            }

        }
        if(cnt>0)
            cout << cnt << " ";
    }
    
    
    
    
    return 0;
}

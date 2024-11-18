#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin.tie(0);

    int n,m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {

        cin >> a[i];
    }
    
    cin >> m;
    unordered_map<int, int> map;
    vector<int> key;

    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        key.push_back(num);
        map[num] = 0;  
    }
    for (int i = 0; i < n; i++)
    {
        map[a[i]] = 1;
    }

    for (int k : key)
    {
        cout << map[k] << "\n";
    }
    return 0;

}

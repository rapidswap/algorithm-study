#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <limits.h>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> haveCard(n);
    for (int i = 0; i < n; i++)
    {
        cin >> haveCard[i];
    }
    sort(haveCard.begin(), haveCard.end());


    int m;
    cin >> m;

    unordered_map<int, int> map;
    vector<int> askCard(m);
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        askCard[i] = a;
        map[a] = 0;
    }

    
    int result = 0;
    for (int i = 0; i < askCard.size(); i++)
    {
        int target = askCard[i];

        int st = 0;
        int ed = n - 1;
        while (st <= ed)
        {
            int mid = (st + ed) / 2;
            if (target > haveCard[mid])
            {
                st = mid + 1;
            }
            if (target < haveCard[mid])
            {
                ed = mid - 1;
            }
            if (target == haveCard[mid])
            {
                map[target]++;
                break;
            }

        }
    }

    for (int i=0;i<map.size();i++)
    {
        cout <<map[askCard[i]]<<" ";
    }
  
    return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <climits>
using namespace std;

int n;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin >> n;

    vector<int> potion(n);
    for (int i = 0; i < n; i++) {
        cin >> potion[i];
    }

    vector<int> cur(2);



    int minPotion = INT_MAX;
    
    int st = 0;
    int ed = n - 1;
    while (st < ed) {
        
        if (0 > potion[st] + potion[ed]) {
            if (minPotion > abs(potion[st] + potion[ed])) {
                minPotion = abs(potion[st] + potion[ed]);
                cur[0] = potion[st];
                cur[1] = potion[ed];
            }
            st++;
        }
        else {
            if (minPotion > abs(potion[st] + potion[ed])) {
                minPotion = abs(potion[st] + potion[ed]);
                cur[0] = potion[st];
                cur[1] = potion[ed];
            }
            ed--;
        }
        if (minPotion == 0) break;
    }
    
    /*for (int i = 0; i < n; i++) {
        int st = 0;
        int ed = n - 1;
        while (st <= ed) {
            int mid = (st + ed) / 2;
            if (mid == i) {
                st = mid + 1;
                continue;
            }
            if (minPotion > abs(potion[i] + potion[mid])) {
                minPotion = abs(potion[i] + potion[mid]);
                st = mid + 1;
                cur[0] = potion[i];
                cur[1] = potion[mid];
                if (minPotion == 0) break;
            }
            else {
                st = mid + 1;
            }
        }
    }*/

    cout << cur[0] << ' ' << cur[1];

    return 0;
}

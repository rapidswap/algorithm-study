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

    for (int i = 0; i < n; i++) {

        int target = -potion[i];  

        int st = 0;
        int ed = n - 1;

        while (st <= ed) {
            int mid = (st + ed) / 2;

            if (mid == i) { 
                if (mid == st) {
                    st++;
                }
                else if (mid == ed) {
                    ed--;
                }
                else {
                    if (abs(potion[mid - 1] - target) <= abs(potion[mid + 1] - target)) {
                        ed = mid - 1;
                    }
                    else {
                        st = mid + 1;
                    }
                }
                continue;
            }

            if (potion[mid] < target) {
                st = mid + 1;
            }
            else {
                ed = mid - 1;
            }
            if (minPotion > abs(potion[i] + potion[mid])) {
                cur[0] = potion[i];
                cur[1] = potion[mid];
                minPotion = abs(potion[i] + potion[mid]);
            }
        }
        if (st < n && st != i && minPotion > abs(potion[i] + potion[st])) {
            cur[0] = potion[i];
            cur[1] = potion[st];
            minPotion = abs(potion[i] + potion[st]);
        }
    }

    cout << cur[0] << ' ' << cur[1];
    return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <climits>
#include <cstring>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    int answer;

    vector<int> potion(N);
    for (int i = 0; i < N; i++) {
        cin >> potion[i];
    }

    if (N == 2) {
        answer = potion[0] + potion[1];
        cout << answer;
        return 0;
    }
    sort(potion.begin(), potion.end());

    int minPotion = INT_MAX;

    
    
    for (int i = 0; i < N; i++) {
        int st = 0;
        int ed = N - 1;

        while (st <= ed) {
            int mid = (st + ed) / 2;

            if (mid == i) {
                if (potion[i] + potion[mid + 1] >= 0) {
                    ed = mid - 1;
                }
                else {
                    st = mid + 1;
                }
                continue;
            }

            if (potion[i] + potion[mid] >= 0) {
                if (minPotion > abs(potion[i] + potion[mid])) {
                    minPotion = abs(potion[i] + potion[mid]);
                    answer = potion[i] + potion[mid];
                }
                ed = mid - 1;
            }
            else {
                if (minPotion > abs(potion[i] + potion[mid])) {
                    minPotion = abs(potion[i] + potion[mid]);
                    answer = potion[i] + potion[mid];
                }
                st = mid + 1;
            }
            //cout <<"MIN: "<< minPotion <<' ' << '/n';

        }
    }

    cout << answer;
    return 0;
}

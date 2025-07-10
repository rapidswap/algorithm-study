#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

ll classRoom[1000001];
int b, c;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> classRoom[i];
    }

    ll cnt = 0;
    
    cin >> b >> c;
    
    for (int i = 0; i < n; i++) {
        classRoom[i] -= b;
        cnt++;
    }

    for (int i = 0; i < n; i++) {
        if (classRoom[i] > 0) {
            if (classRoom[i] / c == 0) {
                cnt++;
            }
            else {
                cnt += classRoom[i] / c;
                if (classRoom[i] % c > 0) cnt++;
            }
        }
    }
    
    cout << cnt;

    return 0;
}

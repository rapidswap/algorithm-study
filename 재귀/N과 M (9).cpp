#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
int arr[10];
int num[10];
bool chk[10];

void func(int cnt)
{
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int last = 0;
    for (int i = 0; i < n; i++) {
        if (!chk[i] && num[i] != last) {
            arr[cnt] = num[i];
            last = arr[cnt];
            chk[i] = true;
            dfs(cnt + 1);
            chk[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    sort(num, num + n);
    func(0);
    return 0;
}

#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;
typedef long long ll;

int N;
vector<int> v(N);
int n[9];
int answer;
bool vist[9];
void func() {
    if (v.size() == N) {
        int temp = 0;
        for (int i = 0; i < N - 1; i++) {
            temp += abs(v[i + 1] - v[i]);
        }
        answer = max(answer, temp);
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!vist[i]) {
            vist[i] = true;
            v.push_back(n[i]);
            func();
            v.pop_back();
            vist[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> n[i];
    }

    func();
    cout << answer;


    return 0;
}
